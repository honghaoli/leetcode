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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        helper(root, sum, path, result);
        return result;
    }
    

private:
    void helper(TreeNode *node, int sum, vector<int> &path, vector<vector<int>> &result) {
        if (!node) return;
        
        path.push_back(node->val);
        
        if (!node->left && !node->right && node->val == sum) {
                result.push_back(path);
        }
        
        helper(node->left, sum - node->val, path, result);
        helper(node->right, sum - node->val, path, result);
        
        path.pop_back();
    }
};