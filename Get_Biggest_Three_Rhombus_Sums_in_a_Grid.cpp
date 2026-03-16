class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<int> sums;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                // size 0 rhombus (single cell)
                sums.insert(grid[i][j]);

