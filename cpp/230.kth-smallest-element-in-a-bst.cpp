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
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return val;
    }

private:
    int val = 0;
    void dfs(TreeNode *node, int &count) {
        if (!node) return;
        dfs(node->left, count);
        count--;
        if (count == 0) {
            val = node->val;
            return;
        }
        dfs(node->right, count);
    }
};
