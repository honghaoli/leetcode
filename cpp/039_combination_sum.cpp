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




// concise
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        findFrom(candidates, 0, target, path, result);
        return result;
    }
    

private:
    void findFrom(vector<int> &candidates, int start, int target, vector<int> &path, vector<vector<int>> &result) {
        if (target == 0) {
            result.push_back(path);
        }
        if (start >= candidates.size()) return;
        for (int i = start; i < candidates.size(); i++) {
            if (target - candidates[i] >= 0) {
                path.push_back(candidates[i]);
                findFrom(candidates, i, target - candidates[i], path, result);
                path.pop_back();
            }
        }
    }
};