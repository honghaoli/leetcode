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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return sum == root->val;
        if (!root->left) return hasPathSum(root->right, sum - root->val);
        if (!root->right) return hasPathSum(root->left, sum - root->val);
        return hasPathSum(root->right, sum - root->val) || hasPathSum(root->left, sum - root->val);
    }
};
