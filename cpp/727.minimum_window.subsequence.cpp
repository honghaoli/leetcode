// improved version
// O(n * m) time, O(m) space
class Solution {
public:
    string minWindow(string S, string T) {
        int n = S.size();
        int m = T.size();
        if (m > n) return "";
        // vector<vector<int>> dp(n, vector<int>(m, -1));   // dp[i][j] = s:   T[0:j] is the subsequence of S[s:i], -1 means no valid start index
        vector<int> dp(m, -1);   // save space dp[][j] = s:   T[0:j] is the subsequence of S[s:i], -1 means no valid start index
        int min_length = INT_MAX;
        string min_str;

        int start = -1;        
        for (int i = 0; i < n; ++i) {
            for (int j = m; j >= 1; --j) {  // order from large to small, avoid overwrite
                if (T[j] == S[i]) {
                    dp[j] = dp[j - 1];
                    if (j + 1 == T.size() && dp[j] >= 0 && i - dp[j] + 1 < min_length) {
                        // found one shorter subsequence
                        min_length = i - dp[j] + 1;
                        min_str = S.substr(dp[j], i - dp[j] + 1);
                    }
                }
            }
            // update dp[0];
            if (S[i] == T[0]) {
                start = i;
                if (m == 1) return T;
            }
            dp[0] = start;
        }
        return min_str;
    }
};



// O(n * m) time, O(n * m ) space
// ref:
// https://leetcode.com/problems/minimum-window-subsequence/discuss/109362/Java-Super-Easy-DP-Solution-(O(mn))
class Solution {
public:
    string minWindow(string S, string T) {
        int n = S.size();
        int m = T.size();
        if (m > n) return "";
        vector<vector<int>> dp(n, vector<int>(m, -1));   // dp[i][j] = s:   T[0:j] is the subsequence of S[s:i], -1 means no valid start index
        int min_length = INT_MAX;
        string min_str;

        int start = -1;
        for (int i = 0; i < n; ++i)  {
            if (S[i] == T[0]) {
                start = i;
                if (m == 1) return T;
            }
            dp[i][0] = start;
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (T[j] == S[i]) {
                    dp[i][j] = dp[i - 1][j - 1];
                    if (j + 1 == T.size() && dp[i][j] >= 0 && i - dp[i][j] + 1 < min_length) {
                        // found one shorter subsequence
                        min_length = i - dp[i][j] + 1;
                        min_str = S.substr(dp[i][j], i - dp[i][j] + 1);
                    }
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return min_str;
    }
};