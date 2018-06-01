class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        if (n == 0) return 0;
        int sum = 0;
        for (int n : nums) 
            sum += n;
        if (abs(S) > sum) return 0;
        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, 0));     // dp[i][j] means up to ith in nums, the number of ways to get target sum == j.
        dp[0][nums[0] + sum]++;
        dp[0][-nums[0] + sum]++;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 2 * sum + 1; j++) {
                if (dp[i - 1][j] != 0) {
                    dp[i][j + nums[i]] += dp[i - 1][j];
                    dp[i][j - nums[i]] += dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][S + sum];
    }
};