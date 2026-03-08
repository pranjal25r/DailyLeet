1class Solution {
2public:
3    bool isMatch(string s, string p) {
4        int n = s.size();
5        int m = p.size();
6
7        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
8        dp[0][0] = true;
9
10        for(int j=2; j<=m; j++){
11            if(p[j-1] == '*')
12            dp[0][j] = dp[0][j-2];
13        }
14        
15        for(int i=1; i<=n; i++){
16            for(int j=1; j<=m; j++){
17                if(p[j-1] == s[i-1] || p[j-1] == '.')
18                dp[i][j] = dp[i-1][j-1];
19
20                else if(p[j-1] == '*'){
21                    dp[i][j] = dp[i][j-2];
22
23                    if(p[j-2] == s[i-1] || p[j-2] == '.')
24                    dp[i][j] = dp[i][j] || dp[i-1][j];
25                }
26            }
27        }
28
29
30        return dp[n][m];
31    }
32};