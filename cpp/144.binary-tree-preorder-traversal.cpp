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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
    

private:
    void preorder(TreeNode *node, vector<int> &result) {
        if (!node) return; 
        result.push_back(node->val);
        if (node->left) preorder(node->left, result);
        if (node->right) preorder(node->right, result);
    }
};