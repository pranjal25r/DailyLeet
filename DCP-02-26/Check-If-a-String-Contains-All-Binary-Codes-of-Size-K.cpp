1class Solution {
2public:
3    bool hasAllCodes(string s, int k) {
4       int n = s.length();
5        
6        if (n < k) return false;
7
8        int total = 1 << k;          // 2^k
9        vector<bool> seen(total, false);
10
11        int num = 0;
12        int count = 0;
13
14        for (int i = 0; i < n; i++) {
15            
16            // Shift left and keep only last k bits
17            num = ((num << 1) & (total - 1)) | (s[i] - '0');
18
19            // Start checking only when window size becomes k
20            if (i >= k - 1) {
21                if (!seen[num]) {
22                    seen[num] = true;
23                    count++;
24
25                    if (count == total)
26                        return true;
27                }
28            }
29        }
30
31        return false;
32    }
33};