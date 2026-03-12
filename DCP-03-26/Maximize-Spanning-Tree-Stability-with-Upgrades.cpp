1
2class Solution {
3public:
4    
5  vector<int> parent, rnk;
6    
7    int find(int x) {
8        if (parent[x] != x)
9            parent[x] = find(parent[x]);
10        return parent[x];
11    }
12    
13    // Returns true if united, false if already in same component
14    bool unite(int x, int y) {
15        int px = find(x), py = find(y);
16        if (px == py) return false;
17        if (rnk[px] < rnk[py]) swap(px, py);
18        parent[py] = px;
19        if (rnk[px] == rnk[py]) rnk[px]++;
20        return true;
21    }
22    
23    void initDSU(int n) {
24        parent.assign(n, 0);
25        rnk.assign(n, 0);
26        iota(parent.begin(), parent.end(), 0);
27    }
28    
29    // Check if spanning tree with min_strength >= mid is achievable
30    bool feasible(int n, vector<vector<int>>& edges, int k, long long mid) {
31        initDSU(n);
32        int used = 0;
33        int upgrades = 0;
34        
35        // Phase 1: Must-include edges (forced, cannot upgrade)
36        // If must-edge strength < mid → impossible
37        // If must-edges form a cycle → impossible (invalid graph)
38        for (auto& e : edges) {
39            int u = e[0], v = e[1], s = e[2], must = e[3];
40            if (must == 1) {
41                if ((long long)s < mid) return false; // Can't upgrade must edges
42                if (!unite(u, v)) return false;       // Must edges form a cycle
43                used++;
44            }
45        }
46        
47        // Phase 2: Non-must edges that qualify WITHOUT upgrade (s >= mid)
48        // Prefer these to save upgrade budget
49        for (auto& e : edges) {
50            int u = e[0], v = e[1], s = e[2], must = e[3];
51            if (must == 0 && (long long)s >= mid) {
52                if (unite(u, v)) used++;
53            }
54        }
55        
56        // Phase 3: Non-must edges that qualify ONLY WITH upgrade (s < mid, s*2 >= mid)
57        // Use upgrade budget here
58        for (auto& e : edges) {
59            int u = e[0], v = e[1], s = e[2], must = e[3];
60            if (must == 0 && (long long)s < mid && (long long)s * 2 >= mid) {
61                if (upgrades < k && unite(u, v)) {
62                    upgrades++;
63                    used++;
64                }
65            }
66        }
67        
68        return used == n - 1;
69    }
70
71public:
72    int maxStability(int n, vector<vector<int>>& edges, int k) {
73        
74        // Early check: Is it even possible to connect all nodes?
75        // Also detect must-edge cycles
76        initDSU(n);
77        for (auto& e : edges) {
78            int u = e[0], v = e[1], must = e[3];
79            if (must == 1) {
80                if (!unite(u, v)) return -1; // Must-edges form a cycle
81            }
82        }
83        // Now check if graph (using all edges) can be connected
84        initDSU(n);
85        for (auto& e : edges) unite(e[0], e[1]);
86        int root = find(0);
87        for (int i = 1; i < n; i++) {
88            if (find(i) != root) return -1; // Graph is disconnected
89        }
90        
91        // Find upper bound for binary search
92        long long maxS = 0;
93        for (auto& e : edges) maxS = max(maxS, (long long)e[2]);
94        
95        // Binary search on stability value
96        // Range: [0, 2*maxS] because max possible after upgrade = 2*maxS
97        long long lo = 0, hi = 2LL * maxS, ans = 0;
98        
99        while (lo <= hi) {
100            long long mid = lo + (hi - lo) / 2;
101            if (feasible(n, edges, k, mid)) {
102                ans = mid;
103                lo = mid + 1;
104            } else {
105                hi = mid - 1;
106            }
107        }
108        
109        return (int)ans;
110    }
111};