
// static variable to bypass the leetcode trick!
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp;
        if (dp.size() < 2) dp = {0, 1};
        int sz = dp.size();
        if (sz <= n) dp.resize(n + 1);
        for (int i = sz; i <= n; ++i) {
            int min_ = i;
            for (int k = 1; k <= int(sqrt(i)); ++k) {
                min_ = min(min_, dp[i - k * k] + 1);
            }
            dp[i] = min_;
        }
        return dp[n];
    }
    
};


// bottom up
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int min_ = i;
            for (int k = 1; k <= int(sqrt(i)); ++k) {
                min_ = min(min_, dp[i - k * k] + 1);
            }
            dp[i] = min_;
        }
        return dp[n];
    }
};



// top down
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        return numSquares(n, dp);
    }

private:
    int numSquares(int i, vector<int> &dp) {
        if (i == 0) return 0;
        if (dp[i] != 0) return dp[i];
        int largest = int(sqrt(i));
        if (largest * largest == i) {
            dp[i] = 1;
            return dp[i];
        }
        int min_ = i;
        for (int k = largest; k >= 1; --k) {
            if (i < k * k) continue;
            min_ = min(min_, numSquares(i - k * k, dp) + 1);
        }
        dp[i] = min_;
        return min_;
    }
};
