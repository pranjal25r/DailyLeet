1class Solution {
2public:
3    int numSpecial(vector<vector<int>>& mat) {
4        int count = 0;
5
6        for(int i = 0; i<mat.size();i++){
7            for(int j = 0; j < mat[0].size();j++){
8                if(mat[i][j] == 1){
9                    int r = 0, c = 0;
10                    for(int k = 0; k < mat[0].size(); k++)
11                    r += mat[i][k];
12
13                for(int k = 0; k < mat.size(); k++)
14                    c += mat[k][j];
15
16                if(r == 1 && c == 1)
17                    count++;
18
19                }
20            }
21        }
22        return count;
23    }
24};