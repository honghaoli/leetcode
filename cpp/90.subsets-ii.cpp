class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> result = {{}};
        subsets(nums, 0, result);
        return result;
    }

private:
    void subsets(vector<int> &nums, int start, vector<vector<int>> &result) {
        if (start >= nums.size()) return;

        // find how many duplicates
        int dup = 0;
        int current = nums[start];
        while (start < nums.size() && nums[start] == current) {
            dup++;
            start++;
        }

        int n = result.size();
        for (int k = 0; k < n; k++) {
            vector<int> tmp = result[k];
            // now we can add 1 ~ dup, so many different choices.
            for (int i = 0; i < dup; i++) {
                tmp.push_back(current);
                result.push_back(tmp);
            }
        }

        // recursively call
        subsets(nums, start, result);
    }
};
