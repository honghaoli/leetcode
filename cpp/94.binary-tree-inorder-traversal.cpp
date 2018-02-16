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
    // Morris traversal, only takes O(1) space.
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        TreeNode *pre, *cur;
        cur = root;
        while (cur) {
            // if left is nullptr, just use current and then move to right.
            if (!cur->left) {
                result.push_back(cur->val);
                cur = cur->right;
            } else {
                // left is not null, put current as the right child of the right-most leaf of left subtree.
                pre = cur->left;
                while (pre->right && pre->right != cur) {
                    pre = pre->right;
                }
                // found the right-most leaf of left subtree
                if (!pre->right) {
                    pre->right = cur;
                    cur = cur->left;        // start from left subtree
                } else {
                    // the right-most leaf is already current node, that means the left subtree is finished.
                    // then change back to the original tree structure
                    pre->right = nullptr;
                    result.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};