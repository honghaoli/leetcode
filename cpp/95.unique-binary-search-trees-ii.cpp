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
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
    

private:
    vector<TreeNode *> generate(int start, int end) {
        vector<TreeNode *> result;
        if (start > end) return result;
        for (int i = start; i <= end; i++) {
            vector<TreeNode *> left = generate(start, i - 1);
            vector<TreeNode *> right = generate(i + 1, end);
            if (left.size() == 0) left.push_back({nullptr});
            if (right.size() == 0) right.push_back({nullptr});
            for (TreeNode *l : left) {
                for (TreeNode *r : right) {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};