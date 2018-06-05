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
    int longestConsecutive(TreeNode* root) {
        longestStartFrom(root);
        return max_length;
    }

private:
    int max_length = 0;

    int longestStartFrom(TreeNode *node) {
        if (!node) return 0;
        int length = 1;
        if (node->left) {
            int left = longestStartFrom(node->left);
            if (node->left->val == node->val + 1) {
                length = max(length, left + 1); 
            }
        }
        if (node->right) {
            int right = longestStartFrom(node->right);
            if (node->right->val == node->val + 1) {
                length = max(length, right + 1); 
            }
        }
        max_length = max(length, max_length);
        return length;
    }
};