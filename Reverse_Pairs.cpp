class Solution {
public:

    void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
