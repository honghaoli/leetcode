

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
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        depth(root);
        return diameter;
    }

private:
    int diameter = 0;
    int depth(TreeNode *node) {
        if (!node) return -1;
        int left = depth(node->left);
        int right = depth(node->right);
        diameter = max(diameter, left + right + 2);
        return max(left, right) + 1;
    }
};




