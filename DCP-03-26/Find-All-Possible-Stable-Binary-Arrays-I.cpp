1class Solution {
2public:
3    const int MOD = 1e9+7;
4    long long dp[201][201][2];
5
6    long long solve(int z, int o, int last, int limit) {
7        if(z==0 && o==0) return 1;
8
9        if(dp[z][o][last] != -1)
10            return dp[z][o][last];
11
12        long long ans = 0;
13
14        if(last == 1) { 
15            // place zeros
16            for(int k=1; k<=limit && k<=z; k++) {
17                ans = (ans + solve(z-k, o, 0, limit)) % MOD;
18            }
19        }
20        else { 
21            // place ones
22            for(int k=1; k<=limit && k<=o; k++) {
23                ans = (ans + solve(z, o-k, 1, limit)) % MOD;
24            }
25        }
26
27        return dp[z][o][last] = ans;
28    }
29
30    int numberOfStableArrays(int zero, int one, int limit) {
31        memset(dp, -1, sizeof(dp));
32
33        long long ans = 0;
34
35        // start with zeros
36        for(int k=1; k<=limit && k<=zero; k++) {
37            ans = (ans + solve(zero-k, one, 0, limit)) % MOD;
38        }
39
40        // start with ones
41        for(int k=1; k<=limit && k<=one; k++) {
42            ans = (ans + solve(zero, one-k, 1, limit)) % MOD;
43        }
44
45        return ans;
46    }
47};