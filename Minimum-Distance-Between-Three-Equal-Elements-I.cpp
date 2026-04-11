1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        unordered_map<int, vector<int>> mp;
5        
6        // store indices
7        for (int i = 0; i < nums.size(); i++) {
8            mp[nums[i]].push_back(i);
9        }
10
11        int ans = INT_MAX;
12
13        for (auto &it : mp) {
14            vector<int> &pos = it.second;
15            
16            if (pos.size() < 3) continue;
17
18            for (int i = 0; i + 2 < pos.size(); i++) {
19                int dist = 2 * (pos[i+2] - pos[i]);
20                ans = min(ans, dist);
21            }
22        }
23
24        return ans == INT_MAX ? -1 : ans;
25    }
26};