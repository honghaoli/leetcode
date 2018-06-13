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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traversal(root);
        return result;
    }

private:
    unordered_set<string> nodeCode;
    unordered_map<TreeNode *, string> nodeToCode;
    vector<TreeNode *> result;
    unordered_set<string> found;

    void traversal(TreeNode *node) {
        if (!node) return;
        traversal(node->left);
        traversal(node->right);
        visit(node);
    }

    void visit(TreeNode *node) {
        string code = encode(node);
        if (nodeCode.count(code) != 0 && found.count(code) == 0) {
            result.push_back(node);
            found.insert(code);
        }
        nodeToCode[node] = code;
        nodeCode.insert(code);
    }

    string encode(TreeNode *node) {
        if (!node) return "#";
        if (nodeToCode.count(node) != 0) return nodeToCode[node];
        nodeToCode[node] = encode(node->left) + "-" + encode(node->right) + "-" + to_string(node->val);
        return nodeToCode[node];
    }
};
