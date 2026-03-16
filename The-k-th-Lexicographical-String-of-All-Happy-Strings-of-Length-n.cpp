1class Solution {
2public:
3    string ans = "";
4    int count = 0;
5
6    void dfs(string &curr, int n, int k) {
7        if(curr.size() == n) {
8            count++;
9            if(count == k) {
10                ans = curr;
11            }
12            return;
13        }
14
15        for(char c : {'a','b','c'}) {
16            if(curr.empty() || curr.back() != c) {
17                curr.push_back(c);
18                dfs(curr, n, k);
19                curr.pop_back();
20            }
21
22            if(ans != "") return;
23        }
24    }
25
26    string getHappyString(int n, int k) {
27        string curr = "";
28        dfs(curr, n, k);
29        return ans;
30    }
31};