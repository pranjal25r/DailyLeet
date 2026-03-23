1class Solution {
2public:
3    int maxProductPath(vector<vector<int>>& grid) {
4        int m = grid.size(), n = grid[0].size();
5        
6        const long long MOD = 1e9 + 7;
7        
8        vector<vector<long long>> maxDp(m, vector<long long>(n));
9        vector<vector<long long>> minDp(m, vector<long long>(n));
10        
11        // base case
12        maxDp[0][0] = minDp[0][0] = grid[0][0];
13        
14        // first column
15        for (int i = 1; i < m; i++) {
16            maxDp[i][0] = minDp[i][0] = maxDp[i-1][0] * grid[i][0];
17        }
18        
19        // first row
20        for (int j = 1; j < n; j++) {
21            maxDp[0][j] = minDp[0][j] = maxDp[0][j-1] * grid[0][j];
22        }
23        
24        // fill DP
25        for (int i = 1; i < m; i++) {
26            for (int j = 1; j < n; j++) {
27                
28                long long a = grid[i][j] * maxDp[i-1][j];
29                long long b = grid[i][j] * minDp[i-1][j];
30                long long c = grid[i][j] * maxDp[i][j-1];
31                long long d = grid[i][j] * minDp[i][j-1];
32                
33                maxDp[i][j] = max({a, b, c, d});
34                minDp[i][j] = min({a, b, c, d});
35            }
36        }
37        
38        long long ans = maxDp[m-1][n-1];
39        
40        if (ans < 0) return -1;
41        return ans % MOD;
42    }
43};