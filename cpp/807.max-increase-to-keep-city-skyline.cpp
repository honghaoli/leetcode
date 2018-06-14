class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> max_rows(n, 0);
        vector<int> max_cols(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                max_rows[i] = max(max_rows[i], grid[i][j]);
                max_cols[j] = max(max_cols[j], grid[i][j]);
            }
        }

        int increase = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int max_height = min(max_rows[i], max_cols[j]);
                increase += max_height - grid[i][j];
            }
        }

        return increase;
    }
};

