class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        sort(nums.begin(), nums.end());
        
        vector<int> dp(n, 1);     // dp[i]: largest size of subset from nums[0:i]
        int max_ = 1;
        int max_index = 0;
        for (int i = 0; i < n; i++) {
            for (int prev = i - 1; prev >= 0; prev--) {
                if (nums[i] % nums[prev] == 0)
                    dp[i] = max(dp[i], dp[prev] + 1);
            }
            if (dp[i] > max_) {
                max_ = dp[i];
                max_index = i;
            }
        }
        
        // now we know the max size and the index of the last number
        vector<int> result(max_, 0);
        for (int i = max_index; i >= 0 && max_ > 0; i--) {
            if (nums[max_index] % nums[i] == 0 && dp[i] == max_) {
                result[--max_] = nums[i];
            }
        }
        
        return result;
    }
};

