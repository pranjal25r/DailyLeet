class Solution {
public:
    string ans = "";
    int count = 0;

    void dfs(string &curr, int n, int k) {
        if(curr.size() == n) {
            count++;
            if(count == k) {
                ans = curr;
            }
            return;
        }

