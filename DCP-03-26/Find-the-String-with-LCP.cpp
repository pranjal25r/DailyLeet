1#include <bits/stdc++.h>
2using namespace std;
3
4class DSU {
5public:
6    vector<int> parent;
7    
8    DSU(int n) {
9        parent.resize(n);
10        for (int i = 0; i < n; i++) parent[i] = i;
11    }
12    
13    int find(int x) {
14        if (parent[x] == x) return x;
15        return parent[x] = find(parent[x]);
16    }
17    
18    void unite(int a, int b) {
19        a = find(a);
20        b = find(b);
21        if (a != b) parent[b] = a;
22    }
23};
24
25class Solution {
26public:
27    string findTheString(vector<vector<int>>& lcp) {
28        int n = lcp.size();
29        DSU dsu(n);
30
31        // Step 1: Union positions with lcp > 0
32        for (int i = 0; i < n; i++) {
33            for (int j = 0; j < n; j++) {
34                if (lcp[i][j] > 0) {
35                    dsu.unite(i, j);
36                }
37            }
38        }
39
40        // Step 2: Assign characters
41        unordered_map<int, char> mp;
42        char curr = 'a';
43        string res(n, '?');
44
45        for (int i = 0; i < n; i++) {
46            int root = dsu.find(i);
47            if (!mp.count(root)) {
48                if (curr > 'z') return "";
49                mp[root] = curr++;
50            }
51            res[i] = mp[root];
52        }
53
54        // Step 3: Recompute LCP
55        vector<vector<int>> dp(n, vector<int>(n, 0));
56
57        for (int i = n - 1; i >= 0; i--) {
58            for (int j = n - 1; j >= 0; j--) {
59                if (res[i] == res[j]) {
60                    if (i == n - 1 || j == n - 1)
61                        dp[i][j] = 1;
62                    else
63                        dp[i][j] = 1 + dp[i + 1][j + 1];
64                } else {
65                    dp[i][j] = 0;
66                }
67            }
68        }
69
70        // Step 4: Validate
71        for (int i = 0; i < n; i++) {
72            for (int j = 0; j < n; j++) {
73                if (dp[i][j] != lcp[i][j]) {
74                    return "";
75                }
76            }
77        }
78
79        return res;
80    }
81};
82