1class Solution {
2public:
3    vector<int> getBiggestThree(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        set<int> sums;
8
9        for(int i = 0; i < m; i++){
10            for(int j = 0; j < n; j++){
11
12                // size 0 rhombus (single cell)
13                sums.insert(grid[i][j]);
14
15                int maxSize = min({i, j, m-1-i, n-1-j});
16
17                for(int k = 1; k <= maxSize; k++){
18
19                    int sum = 0;
20
21                    int x = i-k, y = j;
22
23                    // top -> right
24                    for(int t=0;t<k;t++){
25                        sum += grid[x+t][y+t];
26                    }
27
28                    // right -> bottom
29                    for(int t=0;t<k;t++){
30                        sum += grid[i+t][j+k-t];
31                    }
32
33                    // bottom -> left
34                    for(int t=0;t<k;t++){
35                        sum += grid[i+k-t][j-t];
36                    }
37
38                    // left -> top
39                    for(int t=0;t<k;t++){
40                        sum += grid[i-t][j-k+t];
41                    }
42
43                    sums.insert(sum);
44                }
45            }
46        }
47
48        vector<int> ans(sums.begin(), sums.end());
49        reverse(ans.begin(), ans.end());
50
51        if(ans.size() > 3)
52            ans.resize(3);
53
54        return ans;
55    }
56};