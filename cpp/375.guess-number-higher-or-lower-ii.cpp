class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // some initial easy case
        for (int i = 0; i < n + 1; i++) {
            dp[i][i] = 0;
            if (i + 1 < n + 1)
                dp[i][i + 1] = i;
            if (i + 2 < n + 1)
                dp[i][i + 2] = i + 1;
        }
        //
        return money(1, n, dp);
    }

private:
    int money(int lo, int hi, vector<vector<int>> &dp) {
        if (lo >= hi) return 0;
        if (dp[lo][hi] >= 0) return dp[lo][hi];
        int min_ = INT_MAX;
        for (int mid = lo + 1; mid < hi; mid++) {
            min_ = min(min_, mid + max(money(lo, mid - 1, dp), money(mid + 1, hi, dp)) );
        }
        dp[lo][hi] = min_;
        return min_;
    }
};
