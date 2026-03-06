1class Solution {
2public:
3    bool checkOnesSegment(string s) {
4        bool zero = false;
5        
6        for(int i = 0; i<s.length();i++){
7            if(s[i] == '0')
8            zero = true;
9
10            else if(s[i] == '1' && zero)
11            return false;
12        }
13
14        return true;
15    }
16};