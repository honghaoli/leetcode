// according to solution
// using stack to achieve O(n) time 
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        // find the min so far
        vector<int> mins(n, 0);
        int min_ = nums[0];
        for (int i = 0; i < n; i++) {
            min_ = min(min_, nums[i]);
            mins[i] = min_;
        }
        // from back to front, push num into stack if num > min and num < stack.top();
        // at the same time, check if stack.top() < num and stack.top() > min, if so, return true
        // for simplicity, use vector as stack
        vector<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            // remove all numbers in stack that <= current min
            while (!stk.empty() && stk.back() <= mins[i]) {
                stk.pop_back();
            }
            // check the stack.top()
            if (!stk.empty() && stk.back() < nums[i])
                return true;
            // add new numbers into stack
            if (nums[i] > mins[i] && ( stk.empty() || nums[i] < stk.back() ) )
                stk.push_back(nums[i]);
        }
        return false;
    }
};


// class Solution {
// public:
//     // keep the min and max so far, check if any value in the middle exists
//     // keep all the (min, max) pairs, check any of them.
//     // O(n^2) time, and O(n) space
//     bool find132pattern(vector<int>& nums) {
//         if (nums.size() < 3) return false;
//         int min_ = nums[0];
//         int max_ = nums[0];
//         map<int, int> min_max;
//         for (int &i : nums) {
//             // search map for all valid (min, max) pair
//             auto iter = min_max.lower_bound(i);     // first number >= i
//             for (auto it = min_max.begin(); it != iter; it++) {
//                 if (i > it->first && i < it->second) return true;
//             }
//             // update min and max
//             if (i < min_) {
//                 min_ = i;
//                 max_ = i;
//             } else {
//                 max_ = max(max_, i);
//                 if (max_ > min_) {
//                     min_max[min_] = max_;
//                 }
//             }
//         }
//         return false;
//     }
// };