// from each point, recursively solve the longest path to all neigbhors
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        if (n == 0) return 0;
        m = matrix[0].size();
        if (m == 0) return 0;

        vector<vector<int>> dp(n, vector<int>(m, 0));       // 0 means not calculated yet
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == 0)
                    find(matrix, dp, i, j);
            }
        }
        return longest;
    }

private:
    int longest = 0;
    int n, m;
    const vector<int> dx{0, 1, 0, -1};
    const vector<int> dy{-1, 0, 1, 0};

    int find(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j) {
        if (dp[i][j] > 0) return dp[i][j];
        int length = 1;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] > matrix[i][j])
                length = max(length, 1 + find(matrix, dp, x, y));
        }
        longest = max(longest, length);
        dp[i][j] = length;
        return length;
    }
};
