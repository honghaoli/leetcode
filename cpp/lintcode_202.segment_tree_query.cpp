/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: The root of segment tree.
     * @param start: start value.
     * @param end: end value.
     * @return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode * root, int start, int end) {
        // boundary cases
        if (!root || start < root->start || start > root->end || end > root->end || end < root->start || start > end) return -1;    // maybe?
        if (start == root->start && end == root->end) return root->max;
        int mid = root->start + (root->end - root->start) / 2;
        if (start > mid) return query(root->right, start, end);
        if (end <= mid) return query(root->left, start, end);
        return max(query(root->left, start, mid), query(root->right, mid + 1, end));
    }
};