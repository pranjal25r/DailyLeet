1class Solution {
2public:
3    int numberOfSubmatrices(vector<vector<char>>& grid) {
4        int m = grid.size(), n = grid[0].size();
5        
6        vector<vector<int>> prefX(m, vector<int>(n, 0));
7        vector<vector<int>> prefY(m, vector<int>(n, 0));
8        
9        for (int i = 0; i < m; i++) {
10            for (int j = 0; j < n; j++) {
11                int x = (grid[i][j] == 'X') ? 1 : 0;
12                int y = (grid[i][j] == 'Y') ? 1 : 0;
13                
14                prefX[i][j] = x
15                    + (i > 0 ? prefX[i-1][j] : 0)
16                    + (j > 0 ? prefX[i][j-1] : 0)
17                    - (i > 0 && j > 0 ? prefX[i-1][j-1] : 0);
18                
19                prefY[i][j] = y
20                    + (i > 0 ? prefY[i-1][j] : 0)
21                    + (j > 0 ? prefY[i][j-1] : 0)
22                    - (i > 0 && j > 0 ? prefY[i-1][j-1] : 0);
23            }
24        }
25        
26        int count = 0;
27        for (int i = 0; i < m; i++) {
28            for (int j = 0; j < n; j++) {
29                if (prefX[i][j] == prefY[i][j] && prefX[i][j] > 0) {
30                    count++;
31                }
32            }
33        }
34        
35        return count;
36    }
37};