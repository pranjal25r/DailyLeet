1class Solution {
2public:
3    vector<int> sortByBits(vector<int>& arr) {
4        
5        sort(arr.begin(), arr.end(), [](int a, int b){
6
7            int countA = __builtin_popcount(a);
8            int countB = __builtin_popcount(b);
9
10            if(countA == countB)
11            return a < b; //sort by value if same set bits
12
13            return countA < countB; //sort the number of 1's
14        });
15
16        return arr;
17    }
18};