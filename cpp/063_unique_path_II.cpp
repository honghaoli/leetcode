class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid.at(0).size();
        if (n < 1 || m < 1) return 0;
        if (obstacleGrid[0][0] == 1) return 0;
        
        vector<vector<int>> paths(n, vector<int>(m, -1));
        paths[0][0] = 1;
        return calculate(n-1, m-1, obstacleGrid, paths);
    }
    
private:
    int calculate(int i, int j, vector<vector<int>> &obs, vector<vector<int>> &paths) {
        if (paths[i][j] != -1)
            return paths[i][j];
        
        paths[i][j] = 0;
        if (obs[i][j] != 1) {
            if (i > 0 && obs[i-1][j] == 0)
                paths[i][j] += calculate(i-1, j, obs, paths);
            if (j > 0 && obs[i][j-1] == 0)
                paths[i][j] += calculate(i, j-1, obs, paths);
        }
        
        return paths[i][j];
    }
};
