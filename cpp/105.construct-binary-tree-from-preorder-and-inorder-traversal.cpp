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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() != inorder.size() || preorder.size() < 1) return nullptr;
        return buildTree(preorder, inorder, 0, 0, preorder.size());
    }
    

private:
    TreeNode* buildTree(vector<int> &pre, vector<int> &in, int i1, int i2, int length) {
        TreeNode *root = new TreeNode(pre[i1]);
        int j = i2;
        while (j < i2 + length && in[j] != pre[i1]) j++;
        int left_length = j - i2;
        int right_length = length - left_length - 1;
        if (left_length > 0) {
            root->left = buildTree(pre, in, i1 + 1, i2, left_length);
        }
        if (right_length > 0) {
            root->right = buildTree(pre, in, i1 + left_length + 1, j + 1, right_length);
        }
        return root;
    }
};