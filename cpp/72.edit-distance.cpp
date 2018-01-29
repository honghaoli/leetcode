class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector<int>> dp = vector<vector<int>>(n1 + 1, vector<int>(n2 + 1, -1));
        return calculateDP(word1, word2, n1, n2, dp);
    }

private:
    int calculateDP(string &w1, string &w2, int i, int j, vector<vector<int>> &dp) {
        if (i == 0) return j;
        if (j == 0) return i;

        if (dp[i][j] >= 0)
            return dp[i][j];

        // the last letter is the same
        if (w1[i - 1] == w2[j - 1])
            return calculateDP(w1, w2, i - 1, j - 1, dp);

        // the last letter not the same
        int m = calculateDP(w1, w2, i - 1, j - 1, dp) + 1;
        int m2 = calculateDP(w1, w2, i, j - 1, dp) + 1;
        int m3 = calculateDP(w1, w2, i - 1, j, dp) + 1;
        if (m2 < m)
            m = m2;
        if (m3 < m)
            m = m3;
        dp[i][j] = m;
        return m;
    }
};
