class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;

        // dp[i][j][0] = stable arrays with i zeros, j ones, last digit = 0
        // dp[i][j][1] = stable arrays with i zeros, j ones, last digit = 1
        vector<vector<array<long long, 2>>> dp(
            zero + 1,
            vector<array<long long, 2>>(one + 1, {0LL, 0LL})
        );

        // Base: pure zeros array — only valid if length <= limit
        for (int i = 1; i <= min(zero, limit); i++) dp[i][0][0] = 1;
