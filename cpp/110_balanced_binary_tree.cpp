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
    bool isBalanced(TreeNode* root) {
        return get<1>(height(root));
    }

    tuple<int, bool> height(TreeNode *node) {
        if (node == nullptr) return make_tuple(0, true);

        auto hl = height(node->left);
        if (!get<1>(hl)) return make_tuple(0, false);
        auto hr = height(node->right);
        if (!get<1>(hr)) return make_tuple(0, false);

        int h = max(get<0>(hl), get<0>(hr)) + 1;
        bool b = (abs(get<0>(hl) - get<0>(hr)) <= 1);
        return make_tuple(h, b);
    }
};
