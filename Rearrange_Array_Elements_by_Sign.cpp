class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> posi, nega, ans;

        for(int i=0;i<n;i++){
            if(nums[i] >= 0)
            posi.push_back(nums[i]);
            else
            nega.push_back(nums[i]);
        }

