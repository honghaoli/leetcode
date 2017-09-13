class Solution {
public:
    // from end backward, find the first decreasing num, change it with the larger one, then re-order the rest.
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        
        int i = nums.size() - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) {
            i--;
        }
        
        if (i == 0) {
            std::sort(nums.begin(), nums.end());
            return;
        }
        
        int start = nums[i - 1];
        std::sort(nums.begin() + i - 1, nums.end());
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] > start) {
                int tmp = nums[i - 1];
                nums[i - 1] = nums[j];
                nums[j] = tmp;
                break;
            }
        }
        std::sort(nums.begin() + i, nums.end());
    }
};1
