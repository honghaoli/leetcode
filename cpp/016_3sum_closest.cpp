
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = std::numeric_limits<int>::max();
        int close_sum = 0;
        // sort first
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            // skip duplicate 1st number
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            //
            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end) {
                int sum = nums[start] + nums[end] + nums[i];
                if (sum == target) {
                    return sum;
                } else if (sum > target) {
                    if (sum - target < closest) {
                        closest = sum - target;
                        close_sum = sum;
                    }
                    end--;
                } else {    // sum < target
                    if (target - sum < closest) {
                        closest = target - sum;
                        close_sum = sum;
                    }
                    start++;
                }
            }
        }

        return close_sum;
    }
};
