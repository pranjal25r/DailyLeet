1class Solution {
2public:
3    string findDifferentBinaryString(vector<string>& nums) {
4        int n = nums.size();
5        string ans = "";
6
7        for(int i = 0; i<n; i++){
8            if(nums[i][i] == '0')
9            ans += '1';
10
11            else 
12            ans += '0'; 
13        }
14        return ans;
15    }
16};