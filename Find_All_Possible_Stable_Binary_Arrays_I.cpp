class Solution {
public:
    const int MOD = 1e9+7;
    long long dp[201][201][2];

    long long solve(int z, int o, int last, int limit) {
        if(z==0 && o==0) return 1;

        if(dp[z][o][last] != -1)
            return dp[z][o][last];

        long long ans = 0;

        if(last == 1) { 
