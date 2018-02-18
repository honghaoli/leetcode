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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        helper(root, 0, result);
        return result;
    }
    

private:
    void helper(TreeNode *node, int level, vector<vector<int>> &result) {
        if (!node) return;
        if (level >= result.size()) {
            result.push_back(vector<int>());
        }
        result[level].push_back(node->val);
        helper(node->left, level + 1, result);
        helper(node->right, level + 1, result);
    }
};