class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return sub(nums, nums.size() - 1);
    }
    
private:
    vector<vector<int>> sub(vector<int> &nums, int end) {
        if (end < 0) return {{}};
        
        vector<vector<int>> result = sub(nums, end - 1);
        
        int n = result.size();
        for (int i = 0; i < n; i++) {
            vector<int> tmp = result[i];
            tmp.push_back(nums[end]);
            result.push_back(tmp);
        }
        
        return result;
    }
};




// concise
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result{{}};
        for (int i = 0; i < nums.size(); i++) {
            int n = result.size();
            for (int j = 0; j < n; j++) {
                vector<int> tmp = result[j];
                tmp.push_back(nums[i]);
                result.push_back(tmp);
            }
        }
        return result;
    }
};