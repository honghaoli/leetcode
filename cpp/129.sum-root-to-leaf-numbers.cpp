/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    

private:
    int dfs(TreeNode *node, int pre) {
        if (!node) return 0;
        int cur = pre * 10 + node->val;
        if (!node->left && !node->right) {
            return cur;
        }
        return dfs(node->left, cur) + dfs(node->right, cur);
    }
};