// go through the matrix 4 times, along 4 directions
// calculate how many enemies can be killed along each direction, then sum up.
// O(nm)
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;

        vector<vector<int>> kills = vector<vector<int>>(n, vector<int>(m, 0));
        // from left to right
        for (int i = 0; i < n; ++i) {
            int kill = 0;
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'W') {
                    kill = 0;
                } else if (grid[i][j] == 'E') {
                    ++kill;
                } else if (grid[i][j] == '0') {
                    kills[i][j] += kill;
                }
            }
        }
        // from right to left
        for (int i = 0; i < n; ++i) {
            int kill = 0;
            for (int j = m - 1; j >= 0; --j) {
                if (grid[i][j] == 'W') {
                    kill = 0;
                } else if (grid[i][j] == 'E') {
                    ++kill;
                } else if (grid[i][j] == '0') {
                    kills[i][j] += kill;
                }
            }
        }
        // from top to bottom
        for (int j = 0; j < m; ++j) {
            int kill = 0;
            for (int i = 0; i < n; ++i) {
                if (grid[i][j] == 'W') {
                    kill = 0;
                } else if (grid[i][j] == 'E') {
                    ++kill;
                } else if (grid[i][j] == '0') {
                    kills[i][j] += kill;
                }
            }
        }
        // from bottom to top
        for (int j = 0; j < m; ++j) {
            int kill = 0;
            for (int i = n - 1; i >= 0; --i) {
                if (grid[i][j] == 'W') {
                    kill = 0;
                } else if (grid[i][j] == 'E') {
                    ++kill;
                } else if (grid[i][j] == '0') {
                    kills[i][j] += kill;
                }
            }
        }
        
        // find the max
        int max_kill = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                max_kill = max(max_kill, kills[i][j]);
            }
        }
        //
        return max_kill;
    }
};