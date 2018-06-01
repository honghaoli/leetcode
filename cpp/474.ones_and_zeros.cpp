class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> num0s(strs.size(), 0);
        vector<int> num1s(strs.size(), 0);
        int total1s = 0, total0s = 0;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> counts = count(strs[i]);
            num0s[i] = counts[0];
            num1s[i] = counts[1];
            total0s += counts[0];
            total1s += counts[1];
        }
        if (total0s <= m && total1s <= n) return strs.size();
        // dp
        // dp[m][n] means the max number of strings so far, with m 0s and n 1s
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < strs.size(); i++) {
            for (int k0 = m; k0 >= m - num0s[i]; k0--) {
                for (int k1 = n; k1 >= n - num1s[i]; k1--) {
                    dp[k0][k1] = max(dp[k0][k1], dp[m - num0s[i][n - num1s[i]]]);
                }
            }
        }
        return dp[m][n];
    }

private:
    vector<int> count(string &s) {
        vector<int> result(2, 0);
        for (char c : s) {
            result[c - '0']++;
        }
        return result;
    }
};