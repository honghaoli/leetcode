class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> hash;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                char &c = board[i][j];
                if (c != '.') {
                    string tmp;
                    tmp = "row" + std::to_string(i) + "has" + c;
                    if (hash.count(tmp) > 0)
                        return false;
                    hash.insert(tmp);
                    tmp = "col" + std::to_string(j) + "has" + c;
                    if (hash.count(tmp) > 0)
                        return false;
                    hash.insert(tmp);
                    tmp = "square" + std::to_string((j/3)*3 + i/3) + "has" + c;
                    if (hash.count(tmp) > 0)
                        return false;
                    hash.insert(tmp);
                }
            }
        }
        
        return true;
    }
    

    
};
