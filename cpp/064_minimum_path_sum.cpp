class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n < 1) return -1;
        int m = grid[0].size();
        if (m < 1) return -1;
        
        vector<vector<int>> sums(n, vector<int>(m, -1));
        return calculate(n-1, m-1, grid, sums);
    }
    
private:
    int calculate(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &sums) {
        if (sums[i][j] != -1)
            return sums[i][j];
        
        if (i > 0 && j > 0)
            sums[i][j] = min(grid[i][j] + calculate(i, j-1, grid, sums), grid[i][j] + calculate(i-1, j, grid, sums));
        else if (j > 0)
            sums[i][j] = grid[i][j] + calculate(i, j-1, grid, sums);
        else if (i > 0)
            sums[i][j] = grid[i][j] + calculate(i-1, j, grid, sums);
        else
            sums[i][j] = grid[i][j];
        
        return sums[i][j];
    }   
    
};





// solution 2
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n < 1) return -1;
        int m = grid[0].size();
        if (m < 1) return -1;

        vector<vector<int>> sums(n, vector<int>(m, 0));
        sums[0][0] = grid[0][0];
        for (int i = 1; i < n; i++)
            sums[i][0] = sums[i-1][0] + grid[i][0];        
        for (int i = 1; i < m; i++)
            sums[0][i] = sums[0][i-1] + grid[0][i];
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                sums[i][j] = min(sums[i-1][j], sums[i][j-1]) + grid[i][j];
            }
        }

        return sums[n-1][m-1];
    }   
    
};
