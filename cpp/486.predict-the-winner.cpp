class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return true;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) 
            dp[i][i] = nums[i];
        //
        return (firstScoreMore(nums, 0, n - 1, dp) >= 0);
    }

private:
    int firstScoreMore(vector<int> &nums, int lo, int hi, vector<vector<int>> &dp) {
        if (lo > hi) return 0;
        if (dp[lo][hi] >= 0) return dp[lo][hi];
        int value = max(nums[lo] - firstScoreMore(nums, lo + 1, hi, dp), nums[hi] - firstScoreMore(nums, lo, hi - 1, dp));
        dp[lo][hi] = value;
        return value;
    }
};
