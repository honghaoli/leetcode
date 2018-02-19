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
    // O(n) space
    void recoverTree(TreeNode* root) {
        vector<TreeNode *> seq;
        sequence(root, seq);
        exchange(seq);
    }
    
private:
    void sequence(TreeNode *node, vector<TreeNode *> &seq) {
        if (!node) return;
        sequence(node->left, seq);
        seq.push_back(node);
        sequence(node->right, seq);
    }
    
    void exchange(vector<TreeNode *> &seq) {
        TreeNode *l = nullptr, *s = nullptr;
        for (int i = 1; i < seq.size(); i++) {
            TreeNode *n1 = seq[i - 1];
            TreeNode *n2 = seq[i];
            if (n1->val > n2->val) {
                if (!l) l = n1;     // large is the wrong item of fist time.
                s = n2;             // small is the last wrong item
            }
        }
        swap(l->val, s->val);
    }
    
};