class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return findCombination(candidates, 0, target);
    }
    
    vector<vector<int>> findCombination(vector<int> &candidates, int start, int target) {
        vector<vector<int>> result = {};
        while (start < candidates.size()) {
            if (target == candidates[start]) {
                result.push_back({target});
            } else if (target > candidates[start]) {
                vector<vector<int>> rest = findCombination(candidates, start, target - candidates[start]);
                for (auto &v : rest) {
                    v.push_back(candidates[start]);
                    result.push_back(v);
                }
            }
            start++;
        }
        
        return result;
    }
};
