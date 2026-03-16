1class Fancy {
2public:
3    const long long MOD = 1e9 + 7;
4    vector<long long> seq;
5    long long mul = 1;
6    long long add = 0;
7
8    long long modInverse(long long x) {
9        long long res = 1, power = MOD - 2;
10        while (power) {
11            if (power & 1) res = (res * x) % MOD;
12            x = (x * x) % MOD;
13            power >>= 1;
14        }
15        return res;
16    }
17
18    Fancy() {}
19
20    void append(int val) {
21        long long inv = modInverse(mul);
22        long long normalized = ((val - add) % MOD + MOD) % MOD;
23        normalized = (normalized * inv) % MOD;
24        seq.push_back(normalized);
25    }
26
27    void addAll(int inc) {
28        add = (add + inc) % MOD;
29    }
30
31    void multAll(int m) {
32        mul = (mul * m) % MOD;
33        add = (add * m) % MOD;
34    }
35
36    int getIndex(int idx) {
37        if (idx >= seq.size()) return -1;
38        return (seq[idx] * mul + add) % MOD;
39    }
40};