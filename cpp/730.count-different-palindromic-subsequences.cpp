class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        const int C = 4;   // only has a, b, c, d, 4 chars
        const int kMod = 1E9 + 7;
        // dp[len][c][i] means:
        // start with S[i], with length len substring, how many palindrome starts with char c.
        // see: https://leetcode.com/problems/count-different-palindromic-subsequences/discuss/109514/C++-O(N2)-time-O(N)-memory-with-explanation
        vector<vector<int>> pre2(C, vector<int>(n, 0));
        vector<vector<int>> pre1(C, vector<int>(n, 0));
        vector<vector<int>> curr(C, vector<int>(n, 0));
        // len = 0; num = 0;
        // len = 1; num = 1 only when starting char is c.
        for (int i = 0; i < n; i++)
            curr[ctoi(S[i])][i] = 1;
        //
        for (int len = 2; len <= n; len++) {
            pre2 = pre1;
            pre1 = curr;
            for (int i = 0; i <= n - len; i++) {
                int sum = 2;    // aa and a, there are two at least.
                for (int c = 0; c < C; c++) {
                    sum += pre2[c][i + 1];
                    sum %= kMod;
                }
                for (int c = 0; c < C; c++) {
                    if (ctoi(S[i]) != c) {
                        curr[c][i] = pre1[c][i + 1];
                    } else if (ctoi(S[i + len - 1]) != c) {
                        curr[c][i] = pre1[c][i];
                    } else {
                        curr[c][i] = sum;
                    }
                }
            }
        }
        //
        int result = 0;
        for (int c = 0; c < C; c++) {
            result += curr[c][0];
            result %= kMod;
        }
        return result;
    }

private:
    int inline ctoi(char &c) {
        return c - 'a';
    }
};
