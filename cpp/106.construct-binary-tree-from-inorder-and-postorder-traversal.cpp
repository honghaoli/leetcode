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
    // similar to the other problem (preorder and inorder)
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size() || inorder.size() < 1) return nullptr;
        reverse(postorder.begin(), postorder.end());
        return build(postorder, inorder, 0, 0, inorder.size());
    }
    

private:
    TreeNode* build(vector<int> &post, vector<int> &in, int i1, int i2, int length) {
        TreeNode *root = new TreeNode(post[i1]);
        int j = i2;
        while (j < i2 + length && post[i1] != in[j]) j++;
        int length_left = j - i2;
        int length_right = length - length_left - 1;
        if (length_right > 0) {
            root->right = build(post, in, i1 + 1, j + 1, length_right);
        }
        if (length_left > 0) {
            root->left = build(post, in, i1 + 1 + length_right, i2, length_left);
        }
        return root;
    }
};