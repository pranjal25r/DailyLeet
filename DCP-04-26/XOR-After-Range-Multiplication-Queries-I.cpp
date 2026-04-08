1class Solution {
2public:
3    static const int MOD = 1e9 + 7;
4
5    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
6        int n = nums.size();
7        int B = sqrt(n) + 1;
8
9        for (auto &q : queries) {
10            int l = q[0], r = q[1], k = q[2], v = q[3];
11
12            // For large k → direct
13            if (k >= B) {
14                for (int i = l; i <= r; i += k) {
15                    nums[i] = (1LL * nums[i] * v) % MOD;
16                }
17            } else {
18                // For small k → still simulate (but bounded)
19                for (int i = l; i <= r; i += k) {
20                    nums[i] = (1LL * nums[i] * v) % MOD;
21                }
22            }
23        }
24
25        int ans = 0;
26        for (int x : nums) ans ^= x;
27
28        return ans;
29    }
30};