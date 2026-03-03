1class Solution {
2public:
3    char findKthBit(int n, int k) {
4        if(n==1)
5        return '0';
6
7        int len =(1<<n) -1; //2^n - 1
8        int mid = len/2 + 1;
9
10        if(k == mid)
11        return '1';
12
13        else if(k<mid)
14        return findKthBit(n-1,k);
15
16        else{
17            char ch = findKthBit(n-1, len - k + 1);
18            return(ch=='0') ? '1' : '0'; //invert
19        }
20    }
21};