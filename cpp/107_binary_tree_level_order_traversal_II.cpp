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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        traversal(root, 0, result);
        std::reverse(result.begin(), result.end());
        return result;
    }

private:

    void visit(TreeNode *n, int level, vector<vector<int>> &result) {
        if (level >= result.size()) {
            result.push_back({n->val});
        } else {
            result[level].push_back(n->val);
        }
    }

    void traversal(TreeNode *node, int level, vector<vector<int>> &result) {
        if (node == nullptr) return;
        visit(node, level, result);
        traversal(node->left, level + 1, result);
        traversal(node->right, level + 1, result);
    }
};
