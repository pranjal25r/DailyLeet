1class Solution {
2public:
3    // Check horizontal cuts on grid g
4    // For each cut after row i (top section: rows 0..i, bottom: rows i+1..m-1):
5    // - If s1 == s2, return true
6    // - If diff = |s1 - s2| exists in the larger section AND removing it keeps connectivity
7    bool check(vector<vector<int>>& g) {
8        int m = g.size(), n = g[0].size();
9
10        long long s1 = 0, s2 = 0;
11        unordered_map<long long, int> cnt1, cnt2;
12
13        // Initialize s2 = total sum, cnt2 = all element counts
14        for (auto& row : g)
15            for (int x : row) {
16                s2 += x;
17                cnt2[x]++;
18            }
19
20        for (int i = 0; i < m - 1; i++) {
21            // Move row i from bottom section to top section
22            for (int x : g[i]) {
23                s1 += x;
24                s2 -= x;
25                cnt1[x]++;
26                cnt2[x]--;
27                if (cnt2[x] == 0) cnt2.erase(x);
28            }
29
30            if (s1 == s2) return true;
31
32            // Try removing one cell from the larger section
33            // Section 1 (top): rows 0..i, Section 2 (bottom): rows i+1..m-1
34
35            auto canRemove = [&](long long diff, bool fromTop) -> bool {
36                auto& cnt = fromTop ? cnt1 : cnt2;
37                if (cnt.find(diff) == cnt.end()) return false;
38
39                if (fromTop) {
40                    // Top section has rows 0..i
41                    int rows = i + 1; // number of rows in top
42                    if (rows > 1 && n > 1) return true;
43                    // Single row: must be a corner cell (first or last column)
44                    if (rows == 1)
45                        return (g[0][0] == diff || g[0][n - 1] == diff);
46                    // Single column: must be a corner cell (first or last row of top)
47                    if (n == 1)
48                        return (g[0][0] == diff || g[i][0] == diff);
49                    return true; // rows>1 && n>1 handled above
50                } else {
51                    // Bottom section has rows i+1..m-1
52                    int rows = m - i - 1; // number of rows in bottom
53                    if (rows > 1 && n > 1) return true;
54                    // Single row: must be a corner cell
55                    if (rows == 1)
56                        return (g[i + 1][0] == diff || g[i + 1][n - 1] == diff);
57                    // Single column: must be a corner cell (first or last row of bottom)
58                    if (n == 1)
59                        return (g[i + 1][0] == diff || g[m - 1][0] == diff);
60                    return true;
61                }
62            };
63
64            if (s1 > s2) {
65                long long diff = s1 - s2;
66                if (canRemove(diff, true)) return true;
67            } else {
68                long long diff = s2 - s1;
69                if (canRemove(diff, false)) return true;
70            }
71        }
72        return false;
73    }
74
75    // Rotate grid 90 degrees (transpose) to reuse horizontal check as vertical check
76    vector<vector<int>> rotate(vector<vector<int>>& g) {
77        int m = g.size(), n = g[0].size();
78        vector<vector<int>> t(n, vector<int>(m));
79        for (int i = 0; i < m; i++)
80            for (int j = 0; j < n; j++)
81                t[j][i] = g[i][j];
82        return t;
83    }
84
85    bool canPartitionGrid(vector<vector<int>>& grid) {
86        if (check(grid)) return true;
87        auto t = rotate(grid);
88        return check(t);
89    }
90};