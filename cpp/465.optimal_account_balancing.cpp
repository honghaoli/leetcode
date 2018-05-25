class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> net;
        for (auto &v : transactions) {
            net[v[0]] -= v[2];
            net[v[1]] += v[2];
        }    
        // now the rest of values are all non-zeros
        vector<int> values;
        for (auto iter = net.begin(); iter != net.end(); iter++) {
            if (iter->second != 0) {
                values.push_back(iter->second);
            }
        }
        //
        return dfs(values, 0);
    }


private:
    int dfs(vector<int> &values, int start) {
        if (start + 1 >= values.size()) return 0;
        int tmp = values[start];
        if (tmp == 0) return dfs(values, start + 1);
        int min_count = values.size();      // always less than total number
        for (int i = start + 1; i < values.size(); i++) {
            if (values[i] * tmp < 0) {      // only find opposite values
                values[i] += tmp;
                int count = 1 + dfs(values, start + 1);
                min_count = min(min_count, count);
                values[i] -= tmp;
            }
        }
        return min_count;
    }
};