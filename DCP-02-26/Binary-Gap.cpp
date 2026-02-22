1class Solution {
2public:
3    int binaryGap(int n) {
4        int last = -1, index = 0, maxgap = 0;
5        
6        while(n > 0){
7            if(n & 1){
8                if(last != -1)
9                maxgap = max(maxgap, index - last);
10
11                last = index;
12            }
13        n = n >> 1;
14        index++;
15        }
16        return maxgap;
17    }
18};