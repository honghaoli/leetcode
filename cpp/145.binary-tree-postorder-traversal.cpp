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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
    

private:
    void helper(TreeNode *node, vector<int> &result) {
        if (!node) return;
        helper(node->left, result);
        helper(node->right, result);
        result.push_back(node->val);
    }
};




// iterative solution
// Post order is:  left -> right -> root, consider it inversed.
// similar to Preorder but root -> right -> left
// after this, then reverse the whole vector.
// BUT as the 1st comment of this page:
// https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45551/Preorder-Inorder-and-Postorder-Iteratively-Summarization
// nick46 72 Feb 16, 2016, 4:13 PM
// Again, as I commented at in the most popular answer, strictly speaking, this solution for the post order is incorrect. Even though the final result is correct, imagine if there are topological dependencies among the nodes, the visiting order would be significant. Simply reversing the preorder result isn’t right.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *n = stk.top();
            stk.pop();
            result.push_back(n->val);
            if (n->left) stk.push(n->left);
            if (n->right) stk.push(n->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
