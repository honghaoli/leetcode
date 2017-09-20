class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (hash.count(tmp) > 0)
                hash[tmp].push_back(strs[i]);
            else
                hash[tmp] = {strs[i]};
        }
        
        vector<vector<string>> result;
        for (auto &v : hash) {
            result.push_back(v.second);
        }
        
        return result;
    }
};
