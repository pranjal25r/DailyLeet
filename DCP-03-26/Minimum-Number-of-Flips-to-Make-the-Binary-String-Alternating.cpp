1class Solution {
2public:
3    int minFlips(string s) {
4
5        int n = s.size();
6        s = s + s;
7
8        string alt1 = "", alt2 = "";
9
10        for(int i = 0; i < 2*n; i++){
11            if(i % 2 == 0){
12                alt1 += '0';
13                alt2 += '1';
14            }
15            else{
16                alt1 += '1';
17                alt2 += '0';
18            }
19        }
20
21        int diff1 = 0, diff2 = 0;
22        int res = INT_MAX;
23
24        int left = 0;
25
26        for(int right = 0; right < 2*n; right++){
27
28            if(s[right] != alt1[right]) diff1++;
29            if(s[right] != alt2[right]) diff2++;
30
31            if(right - left + 1 > n){
32
33                if(s[left] != alt1[left]) diff1--;
34                if(s[left] != alt2[left]) diff2--;
35
36                left++;
37            }
38
39            if(right - left + 1 == n){
40                res = min(res, min(diff1, diff2));
41            }
42        }
43
44        return res;
45    }
46};