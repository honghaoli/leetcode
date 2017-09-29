class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if (n < 1) return false;
        int m = board[0].size();
        if (m < 1) return false;
        if (word.size() < 1) return false;

        vector<vector<bool>> checked(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (check(i, j, word, 0, board, checked))
                    return true;
            }
        }

        return false;
    }

private:

    bool check(int i, int j, string &word, int id, vector<vector<char>> &board, vector<vector<bool>> &checked) {
        if (board[i][j] != word[id]) return false;
        if (id == word.size() - 1) return true;

        int n = board.size();
        int m = board[0].size();
        checked[i][j] = true;

        if (i > 0 && !checked[i-1][j]) {
            if (check(i-1, j, word, id+1, board, checked))
                return true;
        }
        if (i < n-1 && !checked[i+1][j]) {
            if (check(i+1, j, word, id+1, board, checked))
                return true;
        }
        if (j > 0 && !checked[i][j-1]) {
            if (check(i, j-1, word, id+1, board, checked))
                return true;
        }
        if (j < m-1 && !checked[i][j+1]) {
            if (check(i, j+1, word, id+1, board, checked))
                return true;
        }

        checked[i][j] = false;
        return false;
    }
};
