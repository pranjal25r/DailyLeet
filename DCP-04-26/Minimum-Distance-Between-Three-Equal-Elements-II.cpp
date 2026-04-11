1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        unordered_map<int, vector<int>> mp;
5        
6        // Step 1: store indices
7        for (int i = 0; i < nums.size(); i++) {
8            mp[nums[i]].push_back(i);
9        }
10        
11        int ans = INT_MAX;
12        
13        // Step 2: process each value
14        for (auto &it : mp) {
15            vector<int> &pos = it.second;
16            
17            if (pos.size() < 3) continue;
18            
19            // Step 3: sliding window of size 3
20            for (int i = 2; i < pos.size(); i++) {
21                ans = min(ans, 2 * (pos[i] - pos[i-2]));
22            }
23        }
24        
25        return ans == INT_MAX ? -1 : ans;
26    }
27};