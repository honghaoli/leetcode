class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n <= 2) return;
        int m = board[0].size();
        if (m <= 2) return;
        
        const char origin = 'O';
        const char replace = '.';
        change_chars(board, origin, replace);
        
        // store all the 0s connected to borders in a queue.
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<int> qu;
        for (int i = 0; i < n; i++) {
            // left border
            if (board[i][0] == replace) {
                qu.push(idx(i, 0, m));
                visited[i][0] = true;
            }
            // right border
            if (board[i][m - 1] == replace) {
                qu.push(idx(i, m - 1, m));
                visited[i][m - 1] = true;
            }
        }
        for (int j = 0; j < m; j++) {
            // upper border
            if (board[0][j] == replace) {
                qu.push(idx(0, j, m));
                visited[0][j] = true;
            }
            // lower border
            if (board[n - 1][j] == replace) {
                qu.push(idx(n - 1, j, m));
                visited[n - 1][j] = true;
            }
        }

        // find all the 0s connected to borders, remain them to 0;
        vector<int> rows = {-1, 0, 1, 0};
        vector<int> cols = {0, -1, 0, 1};
        while (!qu.empty()) {
            vector<int> coord = grid(qu.front(), m);    // get the coordinates row/col
            int row = coord[0], col = coord[1];
            board[row][col] = origin;
            qu.pop();
            // find all neighbors
            for (int i = 0; i < 4; i++) {
                int r = row + rows[i];
                int c = col + cols[i];
                if (r >= 0 && r < n && c >= 0 && c < m && !visited[r][c] && board[r][c] == replace) {
                    qu.push(idx(r, c, m));
                    visited[r][c] = true;
                } 
            }
        }
        
        // finally, change all char = replace to X, which is non-connected to border 0s.
        change_chars(board, replace, 'X');
    }
    

private:
    
    void change_chars(vector<vector<char>> &board, char origin, char replace) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == origin)
                    board[i][j] = replace;
            }
        }
    }
    

    int inline idx(int i, int j, int m) {
        return i * m + j;
    }
    
    
    vector<int> inline grid(int idx, int m) {
        return {idx / m, idx % m};
    }
};