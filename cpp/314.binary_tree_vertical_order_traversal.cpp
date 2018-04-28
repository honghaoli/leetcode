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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        // first find the left most and right most node
        int left = 0;
        int right = 0;
        TreeNode *tmp = root;
        traversal(tmp, 0, left, right);
        // the total size = right - left + 1
        vector<vector<int>> result(right - left + 1, vector<int>());
        // level order traversal
        queue<pair<TreeNode *, int>> q;    // pair of node, node column
        q.push({root, -left});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            result[p.second].push_back(p.first->val);
            if (p.first->left)  q.push({p.first->left, p.second - 1});
            if (p.first->right)  q.push({p.first->right, p.second + 1});
        }
        return result;
    }

private:
    void traversal(TreeNode *node, int col, int &left, int &right) {
        if (!node) return;
        left = min(left, col);
        right = max(right, col);
        traversal(node->left, col - 1, left, right);
        traversal(node->right, col + 1, left, right);
    }
};