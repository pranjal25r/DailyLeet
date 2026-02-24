1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int dfs(TreeNode* root, int curr) {
15        if(root == NULL)
16        return 0;
17
18        curr = (curr << 1) | root -> val; //left shift is equal to curr * 2 and attach current node's bit at right
19        if(root -> left == NULL && root -> right == NULL)
20        return curr;
21
22        return dfs(root->left, curr) + dfs(root->right,curr);
23    }
24    int sumRootToLeaf(TreeNode* root){
25        return dfs(root, 0);
26    }
27};