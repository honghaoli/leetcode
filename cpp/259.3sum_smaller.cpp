class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int total = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1;
            int k = nums.size() - 1;
            for (int j = i + 1; j < k; ++j) {
                while (j < k && nums[i] + nums[j] + nums[k] >= target) {
                    --k;
                }
                total += k - j;
            }
        }
        return total;
    }
};