1class Solution {
2public:
3    int bitwiseComplement(int n) {
4        
5        if(n == 0) return 1;
6
7        int mask = 0;
8        int temp = n;
9
10        while(temp){
11            mask = (mask << 1) | 1; //shifting mask left side and adding 1 at rightmost position
12            temp >>= 1; // shifts the temp to right ie dividing by 2
13        }
14
15        return n ^ mask;
16    }
17};