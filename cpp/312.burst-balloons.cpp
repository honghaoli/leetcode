class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return calculate(nums, 0, n - 1);
    }

private:
    vector<vector<int>> dp;

    int calculate(vector<int> &nums, int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] >= 0) return dp[i][j];
        int left_bound = 1, right_bound = 1;
        if (i > 0) left_bound = nums[i - 1];
        if (j + 1 < nums.size()) right_bound = nums[j + 1];
        // the last burst balloon is k
        int result = 0;
        for (int k = i; k <= j; k++) {
            int tmp = calculate(nums, i, k - 1) + calculate(nums, k + 1, j) + nums[k] * left_bound * right_bound;
            result = max(result, tmp);
        }
        dp[i][j] = result;
        return result;
    }
};
