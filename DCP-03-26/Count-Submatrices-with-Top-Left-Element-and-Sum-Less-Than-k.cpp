1class Solution {
2public:
3    int countSubmatrices(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6        int count = 0;
7
8        for(int i = 0; i<m; i++){
9            for(int j = 0; j<n; j++){
10
11                if(i>0)
12                grid[i][j] += grid[i-1][j];
13
14                if(j>0)
15                grid[i][j] += grid[i][j-1];
16
17                if(i>0 && j>0)
18                grid[i][j] -= grid[i-1][j-1];
19
20                if(grid[i][j] <= k)
21                 count++;
22            }
23        } 
24        return count;
25    }
26};