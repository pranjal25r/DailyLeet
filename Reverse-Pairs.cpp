1class Solution {
2public:
3
4    void merge(vector<int> &arr, int low, int mid, int high) {
5    vector<int> temp; 
6    int left = low;
7    int right = mid + 1;
8
9    while (left <= mid && right <= high) {
10        if (arr[left] <= arr[right]) {
11            temp.push_back(arr[left]);
12            left++;
13        }
14        else {
15            temp.push_back(arr[right]);
16            right++;
17        }
18    }
19    while (left <= mid) {
20        temp.push_back(arr[left]);
21        left++;
22    }
23    while (right <= high) {
24        temp.push_back(arr[right]);
25        right++;
26    }
27
28    for (int i = low; i <= high; i++) {
29        arr[i] = temp[i - low];
30    }
31}
32
33    int countPairs(vector<int> &arr, int low, int mid, int high) {
34        int right = mid + 1;
35        int cnt = 0;
36        for (int i = low; i <= mid; i++) {
37            while (right <= high && arr[i] > 2LL * arr[right]) right++;
38            cnt += (right - (mid + 1));
39        }
40        return cnt;
41    }
42
43    int mergeSort(vector<int> &arr, int low, int high) {
44        int cnt = 0;
45        if (low >= high) return cnt;
46        int mid = (low + high) / 2 ;
47        cnt += mergeSort(arr, low, mid); 
48        cnt += mergeSort(arr, mid + 1, high); 
49        cnt += countPairs(arr, low, mid, high); 
50        merge(arr, low, mid, high); 
51        return cnt;
52    }
53
54
55    int reversePairs(vector<int>& nums) {
56        int n = nums.size();
57        return mergeSort(nums, 0, n - 1);
58    }
59};