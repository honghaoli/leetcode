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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        findLevel(root, result);
        return result;
    }

private:
    int findLevel(TreeNode *node, vector<vector<int>> &result) {
        if (!node) return -1;
        int level = 1 + max(findLevel(node->left, result), findLevel(node->right, result));
        if (result.size() <= level)
            result.resize(level + 1);
        result[level].push_back(node->val);
        return level;
    }
};