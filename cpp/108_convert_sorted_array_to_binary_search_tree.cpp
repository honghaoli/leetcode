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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sorted(nums, 0, nums.size() - 1);
    }

    TreeNode* sorted(vector<int> &nums, int start, int end) {
        if (start > end) return nullptr;

        int mid = (end - start) / 2 + start;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = sorted(nums, start, mid - 1);
        node->right = sorted(nums, mid + 1, end);
        return node;
    }
};
