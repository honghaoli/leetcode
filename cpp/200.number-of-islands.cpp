// BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n < 1) return 0;
        int m = grid[0].size();
        if (m < 1) return 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] || grid[i][j] == '0') continue;
                bfs(grid, visited, i, j);
                count++;
            }
        }
        
        return count;
    }
    

private:
    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j) {
        queue<vector<int>> neighbors;
        neighbors.push(vector<int>{i, j});
        visited[i][j] = true;
        
        while (!neighbors.empty()) {
            vector<int> next = neighbors.front();
            i = next[0];
            j = next[1];
            neighbors.pop();
            //
            if (i > 0 && grid[i - 1][j] != '0' && !visited[i - 1][j]) {
                neighbors.push(vector<int>{i - 1, j});
                visited[i - 1][j] = true;
            }
            if (i < grid.size() - 1 && grid[i + 1][j] != '0' && !visited[i + 1][j]) {
                neighbors.push(vector<int>{i + 1, j});
                visited[i + 1][j] = true;
            }            
            if (j > 0 && grid[i][j - 1] != '0' && !visited[i][j - 1]) {
                neighbors.push(vector<int>{i, j - 1});
                visited[i][j - 1] = true;
            }            
            if (j < grid[0].size() - 1 && grid[i][j + 1] != '0' && !visited[i][j + 1]) {
                neighbors.push(vector<int>{i, j + 1});
                visited[i][j + 1] = true;
            }            
        }
    }
};






// DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n < 1) return 0;
        int m = grid[0].size();
        if (m < 1) return 0;
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    

private:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid.at(0).size() || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};