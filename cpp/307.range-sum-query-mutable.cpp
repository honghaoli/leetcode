// use binary index tree
class NumArray {
public:
    NumArray(vector<int> nums) {
        N = nums.size();
        bitree_ = vector<int>(N + 1, 0);
        nums_ = vector<int>(N, 0);
        for (int i = 0; i < N; ++i) {
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int diff = val - nums_[i];
        nums_[i] = val;
        ++i;
        for ( ; i <= N; i += (i & -i)) {
            bitree_[i] += diff;
        }
        // print_tree();
    }
    
    int sumRange(int i, int j) {
        return sumPrefix(j) - sumPrefix(i - 1);
    }

private:
    int N;
    vector<int> nums_;
    vector<int> bitree_;

    int sumPrefix(int i) {
        int sum = 0;
        ++i;
        for ( ; i > 0; i -= (i & -i)) {
            sum += bitree_[i];
        }
        return sum;
    }
    
    void print_tree() {
        for (int i : bitree_) {
            cout << i << ", ";
        }
        cout << endl;
    }
};








// use array representation of segment tree
class NumArray {
public:
    NumArray(vector<int> nums) {
        buildTree(nums);
    }
    
    void update(int i, int val) {
        if (i < 0 || i >= N) return;
        i += N;
        segment_tree_[i] = val;
        i /= 2;
        while (i > 0) {
            segment_tree_[i] = segment_tree_[2 * i] + segment_tree_[2 * i + 1];
            i /= 2;
        }
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        i += N;
        j += N;
        while (i <= j) {
            // if the left one is a dangling odd branch
            if (i % 2 == 1) {
                sum += segment_tree_[i];
                ++i;
            }
            // if the right one is a dangling even branch
            if (j % 2 == 0) {
                sum += segment_tree_[j];
                --j;
            }
            i /= 2;
            j /= 2;
        }
        return sum;
    }

private:
    int N;
    vector<int> segment_tree_;

    void buildTree(vector<int> &nums) {
        int n = nums.size();
        N = n;
        segment_tree_ = vector<int>(2 * n, 0);
        for (int i = n; i < 2 * n; ++i) {
            segment_tree_[i] = nums[i - n];
        }
        for (int i = n - 1; i > 0; --i) {
            segment_tree_[i] = segment_tree_[2 * i] + segment_tree_[2 * i + 1];
        }
    }
};





// class NumArray {
// public:
//     NumArray(vector<int> nums) {
//         size = nums.size();
//         // root is nullptr if size == 0
//         root = build(0, size - 1, nums);
//     }
    
//     void update(int i, int val) {
//         if (i >= size || i < 0 || !root) return;
//         modify(root, i, val);
//     }
    
//     int sumRange(int i, int j) {
//         if (i > j || i >= size || j < 0 || !root) return 0;  // throw error
//         return query(root, i, j);
//     }

// private:
//     struct SegmentTreeNode {
//         int start, end, sum;
//         SegmentTreeNode *left, *right;
//         SegmentTreeNode(int start, int end, int sum) : start(start), end(end), sum(sum) {}
//     };

//     SegmentTreeNode *root;
//     int size;

//     SegmentTreeNode *build(int start, int end, vector<int> &nums) {
//         if (start > end) return nullptr;
//         SegmentTreeNode *node = new SegmentTreeNode(start, end, nums[start]);
//         if (start < end) {
//             int mid = start + (end - start) / 2;
//             node->left = build(start, mid, nums);
//             node->right = build(mid + 1, end, nums);
//             node->sum = node->left->sum + node->right->sum;
//         }
//         return node;
//     }

//     int query(SegmentTreeNode *root, int start, int end) {
//         if (root->start == start && root->end == end) return root->sum;
//         int mid = root->start + (root->end - root->start) / 2;
//         if (start > mid) return query(root->right, start, end);
//         if (end <= mid) return query(root->left, start, end);
//         return query(root->left, start, mid) + query(root->right, mid + 1, end);
//     }

//     void modify(SegmentTreeNode *root, int i, int value) {
//         if (root->start == root->end && root->start == i) {
//             root->sum = value;
//             return;
//         }
//         int mid = root->start + (root->end - root->start) / 2;
//         if (i > mid) modify(root->right, i, value);
//         else if (i <= mid) modify(root->left, i, value);
//         root->sum = root->left->sum + root->right->sum;
//     }
// };

// /**
//  * Your NumArray object will be instantiated and called as such:
//  * NumArray obj = new NumArray(nums);
//  * obj.update(i,val);
//  * int param_2 = obj.sumRange(i,j);
//  */

