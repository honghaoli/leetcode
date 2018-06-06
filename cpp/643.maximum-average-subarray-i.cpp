class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        // the first k nums
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        //
        int max_sum = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i];
            sum -= nums[i - k];
            max_sum = max(max_sum, sum);
        }

        return (max_sum * 1.0) / (k * 1.0);
    }
};
