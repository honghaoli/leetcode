class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if (n <= 1) return n;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return count(s, n, dp);
    }

private:
    int isPalindromic(string &s, int start, int end, vector<vector<int>> &dp) {
        if (start > end) return 1;
        if (dp[start][end] >= 0) return dp[start][end];
        if (start == end) {
            dp[start][end] = 1;
            return 1;
        }
        if (s[start] == s[end] && isPalindromic(s, start + 1, end - 1, dp)) {
            dp[start][end] = 1;
            return 1;
        } else {
            dp[start][end] = 0;
            return 0;
        }
    }

    int count(string &s, int n, vector<vector<int>> &dp) {
        int total = 0;
        for (int end = 0; end < n; end++) {
            for (int start = 0; start <= end; start++) {
                if (isPalindromic(s, start, end, dp) > 0)
                    total++;
            }
        }
        return total;
    }
};
