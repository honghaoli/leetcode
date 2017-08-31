
// http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() < 1)
            return 0;
        
        int max_so_far = nums.at(0);
        int max_ending_here = nums.at(0);
        for (int i = 1; i < nums.size(); i++) {
            max_ending_here = max(max_ending_here + nums[i], nums[i]);
            if (max_ending_here > max_so_far)
                max_so_far = max_ending_here;
        }
        return max_so_far;
    }
};
