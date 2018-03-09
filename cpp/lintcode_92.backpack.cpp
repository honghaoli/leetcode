class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // dp[i] means the max fill for a backpack with size i
        vector<int> dp(m + 1, 0);
        for (auto &a : A) {
            for (int j = m; j > 0; j--) {
                if (j >= a)
                    dp[j] = max(dp[j], dp[j - a] + a);
            }
        }
        return dp[m];
    }
};