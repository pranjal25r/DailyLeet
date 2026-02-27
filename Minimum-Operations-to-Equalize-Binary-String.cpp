1class Solution {
2public:
3    int minOperations(string s, int k) {
4     int n = s.size();
5        int z = count(s.begin(), s.end(), '0');
6        int ones = n - z;
7        int nk = n - k;
8
9        if (z == 0) return 0;
10
11        for (int t = 1; t <= 2 * n + 2; t++) {
12            long long tk  = (long long)t * k;
13            long long tnk = (long long)t * nk;
14            int upper_need = (t % 2 == 0) ? z : ones;
15
16            if (tk >= z && tk % 2 == z % 2 && tnk >= upper_need)
17                return t;
18        }
19        return -1;
20
21
22    }
23};