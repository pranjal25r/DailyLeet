1class Solution {
2public:
3    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
4        // Direction vectors: N, E, S, W
5        vector<int> dx = {0, 1, 0, -1};
6        vector<int> dy = {1, 0, -1, 0};
7        
8        // Store obstacles
9        unordered_set<string> st;
10        for (auto &o : obstacles) {
11            st.insert(to_string(o[0]) + "#" + to_string(o[1]));
12        }
13        
14        int x = 0, y = 0;
15        int dir = 0; // facing north
16        int maxDist = 0;
17        
18        for (int cmd : commands) {
19            if (cmd == -1) {
20                dir = (dir + 1) % 4; // turn right
21            } 
22            else if (cmd == -2) {
23                dir = (dir + 3) % 4; // turn left
24            } 
25            else {
26                for (int i = 0; i < cmd; i++) {
27                    int nx = x + dx[dir];
28                    int ny = y + dy[dir];
29                    
30                    string key = to_string(nx) + "#" + to_string(ny);
31                    
32                    if (st.count(key)) break;
33                    
34                    x = nx;
35                    y = ny;
36                    
37                    maxDist = max(maxDist, x*x + y*y);
38                }
39            }
40        }
41        
42        return maxDist;
43    }
44};