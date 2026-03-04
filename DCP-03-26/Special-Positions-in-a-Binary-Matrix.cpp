1class Solution {
2public:
3    int numSpecial(vector<vector<int>>& mat) {
4        int m = mat.size();
5        int n = mat[0].size();
6        vector<int> row(m,0), col(n,0);
7
8            for(int i=0;i<m;i++)
9                for(int j=0;j<n;j++)
10                    if(mat[i][j]==1){
11                        row[i]++;
12                        col[j]++;
13                    }
14
15            int ans = 0;
16
17            for(int i=0;i<m;i++)
18                for(int j=0;j<n;j++)
19                    if(mat[i][j]==1 && row[i]==1 && col[j]==1)
20                        ans++;
21
22            return ans;
23    }
24};