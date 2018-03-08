struct TrieNode {
    int val = -1;
    bool found = false;
    TrieNode *next[26];
    TrieNode() = default;
    TrieNode(int val) : val(val) {}
};


class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string &word, int val) {
        TrieNode *n = root;
        for (auto &c : word) {
            if (!n->next[charToInt(c)])
                n->next[charToInt(c)] = new TrieNode();
            n = n->next[charToInt(c)];
        }
        n->val = val;
    }

    vector<int> search_board(vector<vector<char>> &board) {
        vector<int> result;
        if (board.size() < 1 || board.at(0).size() < 1) return result;
        int n = board.size();
        int m = board.at(0).size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }

private:
    TrieNode *root;

    int inline charToInt(char &c) {
        return c - 'a';
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *node, vector<int> &result) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board.at(0).size() || !node) return;
        char c = board[i][j];
        TrieNode *nex = node->next[charToInt(c)];
        if (c == '*' || !nex) return;
        if (nex->val >= 0 && !nex->found) {
            result.push_back(nex->val);
            nex->found = true;
        }
        board[i][j] = '*';
        dfs(board, i - 1, j, nex, result);
        dfs(board, i + 1, j, nex, result);
        dfs(board, i, j - 1, nex, result);
        dfs(board, i, j + 1, nex, result);
        board[i][j] = c;
    }

};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // build trie from words list
        Trie trie = Trie();
        for (int i = 0; i < words.size(); i++) {
            trie.insert(words[i], i);
        }
        // search through board
        vector<int> idx = trie.search_board(board);

        vector<string> result;
        for (auto &i : idx) {
            result.push_back(words[i]);
        }
        return result;
    }
};
