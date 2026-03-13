1class Solution {
2public:
3
4    bool canreduce(long long T, int H, vector<int>& workerTimes){
5        long long total = 0;
6
7        for(long long t: workerTimes){
8            long double val = (long double)T / t;
9            long long x = (sqrt(1 + 8*val)-1)/2; // x = {-1 + sqrt(1+8T/t)} / 2 rearranged x(x+1)/2 equation
10            total += x;
11
12            if(total >= H)
13            return true;
14        }
15        return false;
16    }
17    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
18        
19        long long low = 1;
20        long long high = (long long)*min_element(workerTimes.begin(), workerTimes.end())* mountainHeight * (mountainHeight + 1) / 2;  // t * x(x+1)/2
21        long long ans = high;
22
23        while(low <= high){
24            long long mid = low + (high - low)/2;
25
26            if(canreduce(mid, mountainHeight, workerTimes)){
27                ans = mid;
28                high = mid - 1;
29            }
30            else 
31            low = mid + 1;
32        }
33        return ans;
34    }
35};