/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode dummy(0);
        TreeLinkNode *cur;
        while (root) {
            cur = &dummy;
            while (root) {
                if (root->left) {
                    cur->next = root->left;
                    cur = cur->next;
                }
                if (root->right) {
                    cur->next = root->right;
                    cur = cur->next;
                }
                root = root->next;
            }
            root = dummy.next;
            dummy.next = nullptr;
        }
    }
};