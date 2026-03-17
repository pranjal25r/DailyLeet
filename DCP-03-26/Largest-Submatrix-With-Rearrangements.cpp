1class Solution {
2public:
3    int largestSubmatrix(vector<vector<int>>& matrix) {
4        int m = matrix.size();
5        int n = matrix[0].size();
6        int ans = 0;
7
8        for(int i = 0; i < m; i++) {
9
10            // build heights
11            for(int j = 0; j < n; j++) {
12                if(matrix[i][j] != 0 && i > 0)
13                    matrix[i][j] += matrix[i-1][j];
14            }
15
16            vector<int> height = matrix[i];
17
18            // rearrange columns
19            sort(height.begin(), height.end(), greater<int>());
20
21            for(int j = 0; j < n; j++) {
22                ans = max(ans, height[j] * (j + 1));
23            }
24        }
25
26        return ans;
27    }
28};