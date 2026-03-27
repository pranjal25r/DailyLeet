1class Solution {
2public:
3    bool areSimilar(vector<vector<int>>& mat, int k) {
4        int m = mat.size();
5        int n = mat[0].size();
6
7        for(int i = 0; i < m; i++){
8            for(int j = 0; j < n; j++){
9
10                if(i%2 == 0){
11                    if (mat[i][j] != mat[i][(j + k) % n])
12                    return false;
13                }
14                else{
15                    if(mat[i][j] != mat[i][(j - k % n + n) % n])
16                    return false;
17                }
18            }
19        }
20        return true;
21    }
22};