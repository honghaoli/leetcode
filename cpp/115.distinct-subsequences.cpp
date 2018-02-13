// DP
// O(n^2) time, O(n^2) space.
class Solution {
public:
    int numDistinct(string s, string t) {
        int ns = s.size(), nt = t.size();
        if (ns < nt) return 0;
        vector<vector<int>> dp(nt, vector<int>(ns, 0));
        
        dp[0][0] = (t[0] == s[0] ? 1 : 0);
        for (int j = 1; j < ns; j++) {
            if (t[0] == s[j]) {
                dp[0][j] = dp[0][j - 1] + 1;
            } else {
                dp[0][j] = dp[0][j - 1];
            }
        }
        
        for (int i = 1; i < nt; i++) {
            dp[i][i] = (t[i] == s[i] ? dp[i - 1][i - 1] : 0);
            for (int j = i + 1; j < ns; j++) {
                dp[i][j] = dp[i][j - 1] + (t[i] == s[j] ? dp[i - 1][j - 1] : 0);
            }
        }
        
        return dp[nt - 1][ns - 1]; 
    }
};