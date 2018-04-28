
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
        int diameter = 0;
        traversal(root, diameter);
        return diameter;
    }

private:
    pair<int, int> traversal(TreeNode *node, int &diameter) {
        if (!node) return {-1, -1};
        auto l = traversal(node->left, diameter);
        auto r = traversal(node->right, diameter);
        int left = max(l.first, l.second) + 1;
        int right = max(r.first, r.second) + 1;
        diameter = max(diameter, left + right);
        // cout << node->val << ": " << left << ", " << right << endl;
        return {left, right};
    }
};


