1class Solution {
2public:
3    bool canPartitionGrid(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        long long total = 0;
8
9        // Step 1: total sum
10        for (auto &row : grid) {
11            for (int val : row) {
12                total += val;
13            }
14        }
15
16        // Step 2: must be even
17        if (total % 2 != 0) return false;
18
19        long long target = total / 2;
20
21        // Step 3: horizontal cuts
22        long long curr = 0;
23        for (int i = 0; i < m - 1; i++) {
24            for (int j = 0; j < n; j++) {
25                curr += grid[i][j];
26            }
27            if (curr == target) return true;
28        }
29
30        // Step 4: vertical cuts
31        curr = 0;
32        for (int j = 0; j < n - 1; j++) {
33            for (int i = 0; i < m; i++) {
34                curr += grid[i][j];
35            }
36            if (curr == target) return true;
37        }
38
39        return false;
40    }
41};