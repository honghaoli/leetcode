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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
    

private:
    void preorder(TreeNode *node, vector<int> &result) {
        if (!node) return; 
        result.push_back(node->val);
        if (node->left) preorder(node->left, result);
        if (node->right) preorder(node->right, result);
    }
};



// use stack, iteratively
class Solution {
public:
    // use stack
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        return result;
    }
};



// Morris traversal!!!!!
class Solution {
public:
    // Morris traversal, only takes O(1) space.
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        TreeNode *pre, *cur;
        cur = root;
        while (cur) {
            // if left is nullptr, just use current and then move to right.
            if (!cur->left) {
                result.push_back(cur->val);
                cur = cur->right;
            } else {
                // left is not null, put next node as the right child of the right-most leaf of left subtree.
                pre = cur->left;
                while (pre->right && pre->right != cur) {
                    pre = pre->right;
                }
                // found the right-most leaf of left subtree
                if (!pre->right) {
                    result.push_back(cur->val);
                    pre->right = cur;
                    cur = cur->left;        // start from left subtree
                } else {
                    // the right-most leaf is already current node, that means the left subtree is finished.
                    // then change back to the original tree structure
                    pre->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};