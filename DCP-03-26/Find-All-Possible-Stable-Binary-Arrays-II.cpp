1class Solution {
2public:
3    int numberOfStableArrays(int zero, int one, int limit) {
4        const int MOD = 1e9 + 7;
5
6        // dp[i][j][0] = stable arrays with i zeros, j ones, last digit = 0
7        // dp[i][j][1] = stable arrays with i zeros, j ones, last digit = 1
8        vector<vector<array<long long, 2>>> dp(
9            zero + 1,
10            vector<array<long long, 2>>(one + 1, {0LL, 0LL})
11        );
12
13        // Base: pure zeros array — only valid if length <= limit
14        for (int i = 1; i <= min(zero, limit); i++) dp[i][0][0] = 1;
15
16        // Base: pure ones array — only valid if length <= limit
17        for (int j = 1; j <= min(one, limit);  j++) dp[0][j][1] = 1;
18
19        // Fill only when BOTH i>=1 AND j>=1
20        // (boundary rows/cols already handled by base cases above)
21        for (int i = 1; i <= zero; i++) {
22            for (int j = 1; j <= one; j++) {
23
24                // Append a 0: previous array had (i-1) zeros and j ones
25                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
26                // Subtract arrays that now have (limit+1) consecutive zeros
27                if (i > limit)
28                    dp[i][j][0] = (dp[i][j][0] - dp[i-limit-1][j][1] + MOD) % MOD;
29
30                // Append a 1: previous array had i zeros and (j-1) ones
31                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1]) % MOD;
32                // Subtract arrays that now have (limit+1) consecutive ones
33                if (j > limit)
34                    dp[i][j][1] = (dp[i][j][1] - dp[i][j-limit-1][0] + MOD) % MOD;
35            }
36        }
37
38        return (int)((dp[zero][one][0] + dp[zero][one][1]) % MOD);
39    }
40};