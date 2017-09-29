class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n < k || k <= 0) return {};
        
        if (k == 1) {
            vector<vector<int>> result(n, vector<int>(1,0));
            for (int i = 0; i < n; i++)
                result[i] = {i + 1};
            return result;
        }
        

        vector<vector<int>> c2 = combine(n - 1, k - 1);
        for (auto &v : c2)
            v.push_back(n);
        
        vector<vector<int>> c1 = combine(n - 1, k);
        c2.reserve(c1.size() + c2.size());
        c2.insert(c2.end(), c1.begin(), c1.end());
        // for (auto &v : combine(n - 1, k))
            // c2.push_back(v);
        
        return c2;
    }
};
