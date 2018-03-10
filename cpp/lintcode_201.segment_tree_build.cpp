/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param start: start value.
     * @param end: end value.
     * @return: The root of Segment Tree.
     */
    SegmentTreeNode *build(int start, int end) {
        if (start > end) return nullptr;
        SegmentTreeNode *node = new SegmentTreeNode(start, end);
        if (start == end) return node;
        int mid = start + (end - start) / 2;
        node->left = build(start, mid);
        node->right = build(mid + 1, end);
        return node;
    }
};