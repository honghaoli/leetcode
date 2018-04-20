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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        tran(root, 0, result);

        // then reverse the odd row;
        for (int i = 1; i < result.size(); i += 2) {
            reverse(result[i].begin(), result[i].end());
        }
        return result;
    }

private:
    void tran(TreeNode *node, int level, vector<vector<int>> &result) {
        if (!node) return;
        if (level >= result.size())
            result.push_back({});
        result[level].push_back(node->val);
        tran(node->left, level + 1, result);
        tran(node->right, level + 1, result);
    }
};
