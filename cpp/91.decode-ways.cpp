class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n < 1) return 0;
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        dp[n - 1] = (s[n - 1] == '0' ? 0 : 1);
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                dp[i] = dp[i + 1] + dp[i + 2];
            } else if (s[i] == '0') {  // very important here!!!!
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
            }
        }
        return dp[0];
    }
    
};




// time O(n), space O(1)
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n < 1) return 0;
        int dp2 = 1;
        int dp1 = (s[n - 1] == '0' ? 0 : 1);
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                int tmp = dp1;
                dp1 += dp2;
                dp2 = tmp;
            } else if (s[i] == '0') {
                dp2 = dp1;
                dp1 = 0;
            } else {
                dp2 = dp1;
            }
        }
        return dp1;
    }
    
};