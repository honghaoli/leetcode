class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        permuteFrom(nums, 0, result);
        return result;
    }
    
private:
    void permuteFrom(vector<int> &nums, int start, vector<vector<int>> &result) {
        if (start == nums.size() - 1) {
            result.push_back(nums);
            return;
        }
        
        unordered_set<int> hash;
        for (int i = start; i < nums.size(); i++) {
            if (hash.count(nums[i]) > 0) continue;
            hash.insert(nums[i]);
            swap(nums[i], nums[start]);
            permuteFrom(nums, start + 1, result);
            swap(nums[i], nums[start]);
        }
    }
};
