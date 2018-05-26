class Solution {
public:
    // keep the min and max so far, check if any value in the middle exists
    // keep all the (min, max) pairs, check any of them.
    // O(n^2) time, and O(n) space
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int min_ = nums[0];
        int max_ = nums[0];
        map<int, int> min_max;
        for (int &i : nums) {
            // search map for all valid (min, max) pair
            auto iter = min_max.lower_bound(i);     // first number >= i
            for (auto it = min_max.begin(); it != iter; it++) {
                if (i > it->first && i < it->second) return true;
            }
            // update min and max
            if (i < min_) {
                min_ = i;
                max_ = i;
            } else {
                max_ = max(max_, i);
                if (max_ > min_) {
                    min_max[min_] = max_;
                }
            }
        }
        return false;
    }
};