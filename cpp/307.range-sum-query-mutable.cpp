class NumArray {
public:
    NumArray(vector<int> nums) {
        size = nums.size();
        // root is nullptr if size == 0
        root = build(0, size - 1, nums);
    }
    
    void update(int i, int val) {
        if (i >= size || i < 0 || !root) return;
        modify(root, i, val);
    }
    
    int sumRange(int i, int j) {
        if (i > j || i >= size || j < 0 || !root) return 0;  // throw error
        return query(root, i, j);
    }

private:
    struct SegmentTreeNode {
        int start, end, sum;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int start, int end, int sum) : start(start), end(end), sum(sum) {}
    };

    SegmentTreeNode *root;
    int size;

    SegmentTreeNode *build(int start, int end, vector<int> &nums) {
        if (start > end) return nullptr;
        SegmentTreeNode *node = new SegmentTreeNode(start, end, nums[start]);
        if (start < end) {
            int mid = start + (end - start) / 2;
            node->left = build(start, mid, nums);
            node->right = build(mid + 1, end, nums);
            node->sum = node->left->sum + node->right->sum;
        }
        return node;
    }

    int query(SegmentTreeNode *root, int start, int end) {
        if (root->start == start && root->end == end) return root->sum;
        int mid = root->start + (root->end - root->start) / 2;
        if (start > mid) return query(root->right, start, end);
        if (end <= mid) return query(root->left, start, end);
        return query(root->left, start, mid) + query(root->right, mid + 1, end);
    }

    void modify(SegmentTreeNode *root, int i, int value) {
        if (root->start == root->end && root->start == i) {
            root->sum = value;
            return;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if (i > mid) modify(root->right, i, value);
        else if (i <= mid) modify(root->left, i, value);
        root->sum = root->left->sum + root->right->sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

