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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
    
    bool isMirror(TreeNode *n1, TreeNode *n2) {
        if (n1 == nullptr || n2 == nullptr) return n1 == n2;
        return (n1->val == n2->val) && isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left);
    }
};
