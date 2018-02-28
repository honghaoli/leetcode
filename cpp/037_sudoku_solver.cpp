class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        unordered_set<string> givenSitesHash;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.at(0).size(); j++) {
                if (board[i][j] != '.')
                    insertHash(i, j, board[i][j], givenSitesHash);
            }
        }
        
        solve(board, givenSitesHash);
    }
    
    /////
    
    bool solve(vector<vector<char>> &board, unordered_set<string> &hash) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.at(0).size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (checkValid(i, j, c, hash)) {
                            board[i][j] = c;
                            insertHash(i, j, c, hash);
                            if (solve(board, hash)) return true;
                            board[i][j] = '.';
                            removeHash(i, j, c, hash);
                        }
                    }
                    return false;
                }
            }
        }   
        return true;
    }
    
    void removeHash(int i, int j, char c, unordered_set<string> &hash) {
        for (auto &s : stringsForAll(i, j, c)) {
            hash.erase(s);
        }                
    }
    
    
    void insertHash(int i, int j, char c, unordered_set<string> &hash) {
        for (auto &s : stringsForAll(i, j, c)) {
            hash.insert(s);
        }        
    }
    
    bool checkValid(int i, int j, char c, unordered_set<string> &hash) {
        for (auto &s : stringsForAll(i, j, c)) {
            if (hash.count(s) > 0)
                return false;            
        }
        return true;
    }
    
    vector<string> stringsForAll(int i, int j, char c) {        
        vector<string> s;
        s.push_back("row" + to_string(i) + "has" + c);
        s.push_back("col" + to_string(j) + "has" + c);
        s.push_back("square" + to_string(squareIndex(i, j)) + "has" + c);
        return s;
    }
    
    
    int squareIndex(int i, int j) {
        return (i / 3) * 3 + (j / 3);
    }
};







// faster 8ms
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        col = vector<vector<bool>>(N, vector<bool>(N, false));
        row = vector<vector<bool>>(N, vector<bool>(N, false));
        square = vector<vector<bool>>(N, vector<bool>(N, false));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == '.') continue;
                int k = charToInt(board[i][j]);
                col[j][k - 1] = true;
                row[i][k - 1] = true;
                square[toSquare(i * N + j)][k - 1] = true;
                //cout << i << ", " << j << ", " << toSquare(i * N + j) << ", " << k << endl;
            }
        }
        dfs(board, 0);
    }
    
private:
    const int N = 9;
    vector<vector<bool>> col, row, square;
    
    int inline charToInt(char c) {
        return c - '0';
    }
    
    char inline intToChar(int i) {
        return i + '0';
    }
    
    int inline toCol(int idx) {
        return idx % N;
    }
    
    int inline toRow(int idx) {
        return idx / N;
    }
    
    int inline toSquare(int idx) {
        return (idx / N / 3) * 3 + (idx % N) / 3;
    }
    
    bool dfs(vector<vector<char>> &board, int idx) {
        if (idx == N * N) return true;
        
        int i = toRow(idx);
        int j = toCol(idx);
        int s = toSquare(idx);
        if (board[i][j] != '.')
            return dfs(board, idx + 1);
        
        for (int k = 1; k <= 9; k++) {
            if (!col[j][k - 1] && !row[i][k - 1] && !square[s][k - 1]) {
                board[i][j] = intToChar(k);
                row[i][k - 1] = true;
                col[j][k - 1] = true;
                square[s][k - 1] = true;
                
                if (dfs(board, idx + 1)) return true;
                
                board[i][j] = '.';
                row[i][k - 1] = false;
                col[j][k - 1] = false;
                square[s][k - 1] = false;
            }
        }
        
        return false;
    }
};