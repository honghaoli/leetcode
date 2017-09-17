class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return findRest(candidates, 0, target);
    }
    
    vector<vector<int>> findRest(vector<int> &candidates, int start, int target) {
        if (target == 0) return {{}};
        
        vector<vector<int>> result;
        while (start < candidates.size()) {
            int num = candidates[start];
            if (target == num) {
                result.push_back({num});
                break;
            } else if (target > num) {
                // find all the duplicates, assume all the rest duplicates must be added.
                // to avoid duplicate combination in final result.
                int end = start + 1;
                while (end < candidates.size() && candidates[end] == num)
                    end++;
                int new_target = target - num * (end - start);

                vector<vector<int>> tmp = findRest(candidates, end, new_target);
                
                for (auto &v : tmp) {
                    // append all duplicates to the vectors.
                    int count = end - start;
                    while (count-- > 0)
                        v.push_back(num);
                    result.push_back(v);
                }
                
                // increment the start index only by one
                // so different numbers of duplicates will all be covered.
                start++;
            } else {
                break;
            }
        }
        
        return result;
    }
};
