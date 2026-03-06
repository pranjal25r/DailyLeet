1class Solution {
2public:
3    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
4        
5        if(nums1.size() > nums2.size())
6            return findMedianSortedArrays(nums2, nums1);
7
8        int n1 = nums1.size();
9        int n2 = nums2.size();
10
11        int low = 0, high = n1;
12
13        while(low <= high)
14        {
15            int cut1 = (low + high) / 2;
16            int cut2 = (n1 + n2 + 1)/2 - cut1;
17
18            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1-1];
19            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1];
20
21            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
22            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];
23
24            if(l1 <= r2 && l2 <= r1)
25            {
26                if((n1+n2)%2 == 0)
27                    return (max(l1,l2) + min(r1,r2)) / 2.0;
28                else
29                    return max(l1,l2);
30            }
31            else if(l1 > r2)
32                high = cut1 - 1;
33            else
34                low = cut1 + 1;
35        }
36
37        return 0.0;
38    }
39};