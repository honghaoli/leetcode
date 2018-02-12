class Solution {
public:
    // time O(n1 * n2), space O(n1 * n2)
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) return false;
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return isInterleave(s1, 0, s2, 0, s3, dp);
    }
    

private:
    bool isInterleave(string &s1, int i1, string &s2, int i2, string &s3, vector<vector<int>> &dp) {
        // make sure i3 == i1 + i2
        int i3 = i1 + i2;
        if (i3 == s3.size()) return true;
        if (dp[i1][i2] != -1) return dp[i1][i2];
        
        bool b1 = (i1 < s1.size()) && (s1[i1] == s3[i3]) && isInterleave(s1, i1 + 1, s2, i2, s3, dp);
        bool b2 = (i2 < s2.size()) && (s2[i2] == s3[i3]) && isInterleave(s1, i1, s2, i2 + 1, s3, dp);
        dp[i1][i2] = b1 || b2;
        return dp[i1][i2];
    }
};




class Solution {
public:
    // bottom-up DP
    // time O(n1 * n2), space O(n1 * n2)
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n3 != n1 + n2) return false;
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, true));
        for (int i1 = 0; i1 <= n1; i1++) {
            for (int i2 = 0; i2 <= n2; i2++) {
                if (i1 == 0 && i2 == 0) 
                    dp[i1][i2] = true;
                else {
                    int i3 = i1 + i2;
                    bool b1 = (i1 > 0) && (s1[i1 - 1] == s3[i3 - 1]) && dp[i1 - 1][i2];
                    bool b2 = (i2 > 0) && (s2[i2 - 1] == s3[i3 - 1]) && dp[i1][i2 - 1];
                    dp[i1][i2] = b1 || b2;
                }
            }
        } 
        return dp[n1][n2];
    }
};




// reduce space to O(n)
class Solution {
public:
    // bottom-up DP
    // time O(n1 * n2), space O(n2)
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n3 != n1 + n2) return false;
        vector<bool> dp(n2 + 1, true);
        for (int i1 = 0; i1 <= n1; i1++) {
            for (int i2 = 0; i2 <= n2; i2++) {
                if (i1 == 0 && i2 == 0) 
                    dp[i2] = true;
                else {
                    int i3 = i1 + i2;
                    bool b1 = (i1 > 0) && (s1[i1 - 1] == s3[i3 - 1]) && dp[i2];
                    bool b2 = (i2 > 0) && (s2[i2 - 1] == s3[i3 - 1]) && dp[i2 - 1];
                    dp[i2] = b1 || b2;
                }
            }
        } 
        return dp[n2];
    }
};