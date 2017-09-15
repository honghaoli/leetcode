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
