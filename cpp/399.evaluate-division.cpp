class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        build_graph(equations, values);
        vector<double> result;
        for (auto &p : queries) {
            result.push_back(lookup_table(p));
        }
        return result;
    }

private:
    unordered_map<string, bool> visited;
    unordered_map<string, unordered_map<string, double>> table;

    void build_graph(vector<pair<string, string>> &equations, vector<double>& values) {
        // deal with input
        for (int i = 0; i < values.size(); i++) {
            string &from = equations[i].first;
            string &to = equations[i].second;
            double v = values[i];
            visited[from] = false;
            visited[to] = false;
            table[from][to] = v;
            table[to][from] = 1.0 / v;
        }
    }

    double lookup_table(pair<string, string> &query) {
        string &from = query.first;
        string &to = query.second;
        if (visited.count(from) == 0 || visited.count(to) == 0)
            return -1.0;    // no vertex found in the graph.
        if (from == to)
            return 1.0;     // the same vertex;
        auto copy = visited;
        return dfs(from, to, copy);
    }

    double dfs(const string &from, const string &to, unordered_map<string, bool> &visited) {
        visited[from] = true;
        if (from == to) return 1.0;
        for (auto iter = table[from].begin(); iter != table[from].end(); iter++) {
            if (visited[iter->first]) continue;     // already visited;
            double result = dfs(iter->first, to, visited);
            if (result > 0)
                return result * table[from][iter->first];
        }
        return -1.0;
    }
};

