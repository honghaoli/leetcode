class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n <= 1) return 0;

        // dp[i]: min cut for s[0, i]
        vector<int> dp(n, 0);
        // p[i][j]: whether s[i, j] is palindrome
        vector<vector<bool>> p(n, vector<bool>(n, false));
        // calculate all p[i][j];
        for (int i = n - 1; i >= 0; i--) {
            p[i][i] = true;
            for (int j = i + 1; j < n; j++) {
                p[i][j] = (s[i] == s[j] && (i + 1 >= j - 1 || p[i + 1][j - 1] ) );
            }
        }
        // calculate all dp[i]
        for (int end = 0; end < n; end++) {
            if (p[0][end]) {
                dp[end] = 0;  
                continue;
            }
            dp[end] = end;
            for (int cut = end; cut > 0; cut--) {
                if (p[cut][end]) {
                    dp[end] = min(dp[end], dp[cut - 1] + 1);
                }
            }
        }
        
        return dp[n - 1];
    }
    
};


// according to solution:
// the 2 for loops can be combined into 1, with some tricks
// calcualte p[i][j] and dp[i] at the same time 


// The best solution comes from the discussion!!!!!
// only O(n) space!!!!
class Solution {
public:
    // from discussion
    // https://leetcode.com/problems/palindrome-partitioning-ii/discuss/42198/My-solution-does-not-need-a-table-for-palindrome-is-it-right-It-uses-only-O(n)-space.
    // O(n^2) time
    // O(n) space
    int minCut(string s) {
        int n = s.size();
        if (n <= 1) return 0;

        // dp[end]: minCut for s[0, end)
        vector<int> dp;
        // initial as the number of char - 1, max possbile cuts
        for (int i = 0; i <= n; i++) {
            dp.push_back(i - 1);
        }
        // from each mid index, expand to both left/right
        // .......aba...
        // |<-X->| ^
        // |<---Y-->|
        // if the expand is palindrome, then minCut(Y) = minCut(X) + 1 
        for (int mid = 0; mid < n; mid++) {
            // odd palindrome, e.g., "aba"
            for (int l = 0; l <= mid && l + mid < n && s[mid + l] == s[mid - l]; l++) {
                dp[mid + l + 1] = min(dp[mid + l + 1], dp[mid - l] + 1);
            }
            // even palindrome, e.g., "abba"
            for (int l = 0; l <= mid && l + mid + 1 < n && s[mid + l + 1] == s[mid - l]; l++) {
                dp[mid + l + 2] = min(dp[mid + l + 2], dp[mid - l] + 1);
            }
        }
        
        return dp[n];
    }
};