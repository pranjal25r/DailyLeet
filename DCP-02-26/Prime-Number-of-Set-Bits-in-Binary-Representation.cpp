1class Solution {
2public:
3
4    bool isprime(int n){
5        if(n<2) return false;
6        for(int i = 2;i * i <= n; i++){
7            if(n % i == 0)
8            return false;
9        }
10        return true;
11    }
12
13    int countPrimeSetBits(int left, int right) {
14        int count = 0;
15
16        for(int i = left; i <= right; i++){
17            int setB = __builtin_popcount(i);
18            if(isprime(setB))
19            count++;
20        }
21        return count;
22    }
23};