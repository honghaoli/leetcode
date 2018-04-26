class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, set<string>> hash;
        for (auto &p : tickets) {
            if (hash.count(p.first) == 0)
                hash[p.first] = set<string>();
            hash[p.first].insert(p.second);
        }
        //
        string start = "JFK";
        vector<string> path{start};
        dfs(start, path, hash);
        return path;
    }

private:
    bool dfs(string &curr, vector<string> &path, unordered_map<string, set<string>> &hash) {
        while (hash[curr].size() > 0) {
            string next = *hash[curr].begin();
            hash[curr].erase(hash[curr].begin()]);
            dfs(next, path, hash);
        }
        path.push_back(next);
    }
};
