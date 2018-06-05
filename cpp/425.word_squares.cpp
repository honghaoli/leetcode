class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        // a very simple prefix map.
        for (auto &w : words) {
            for (int i = 1; i < w.size(); ++i) {
                prefix[words.substr(0, i)].push_back(words);
            }
        }
        size = words.at(0).size();
        vector<vector<string>> result;
        vector<string> path;
        for (auto &w : words) {
            path = {w};
            dfs(1, result, path);
        }
    }

private:
    int size;
    unordered_map<string, vector<string>> prefix;

    void dfs(int n, vector<vector<string>> &result, vector<string> &path) {
        if (n == size) {
            result.push_back(path);
            return;
        }
        // build prefix for the next row word
        string next;
        for (int i = 0; i < path.size(); ++i) {
            next.push_back(path[i][k]);
        }
        // try all the word with prefix 
        for (string &word : prefix[next]) {
            path.push_back(word);
            dfs(n + 1, result, path);
            path.pop_back();
        }
    }
};