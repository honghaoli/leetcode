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
    int maxPathSum(TreeNode* root) {
        // maxSum = numeric_limits<int>::min();
        maxSum = INT_MIN;
        endAt(root);
        return maxSum;
    }
    

private:
    int maxSum;
    int endAt(TreeNode *node) {
        if (!node) return 0;
        // in case the path is negative
        int left = max(0, endAt(node->left));
        int right = max(0, endAt(node->right));
        // if node is the middle point
        if (left + right + node->val > maxSum)
            maxSum = left + right + node->val;
        // if node is the end point
        return node->val + max(left, right);
    }
};