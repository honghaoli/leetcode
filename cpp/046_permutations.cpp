class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            addOne(nums, i, result);
        }
        return result;
    }
    
    void addOne(vector<int> &nums, int id, vector<vector<int>> &result) {
        if (result.size() == 0) {
            result = {{nums[id]}};
            return;
        }
        
        int s = result.size();
        for (int j = 0; j < s; j++) {
            for (int i = 0; i < result[j].size(); i++) {
                vector<int> dup = result[j];
                dup.insert(dup.begin() + i, nums[id]);
                result.push_back(dup);
            }
            result[j].push_back(nums[id]);
        }
    }
};




// better solution

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteFrom(nums, 0, result);
        return result;
    }
    
    void permuteFrom(vector<int> &nums, int start, vector<vector<int>> &result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            permuteFrom(nums, start + 1, result);
            swap(nums[i], nums[start]);
        }
    }
};
