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
    bool isValidBST(TreeNode* root) {
        return subTreeInRange(root, nullptr, nullptr);
    }
    

private:
    bool subTreeInRange(TreeNode *node, TreeNode *minNode, TreeNode *maxNode) {
        if (!node) return true;
        if (minNode && node->val <= minNode->val) return false;
        if (maxNode && node->val >= maxNode->val) return false;
        return subTreeInRange(node->left, minNode, node) && subTreeInRange(node->right, node, maxNode);
    }
};