class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (nums.size() == 0) return false;
        if (k == 1) return true;
        
        sort(nums.rbegin(), nums.rend());

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        if (nums[0] > sum / k) return false;

        vector<bool> used(nums.size(), false);

        for (int i = 1; i < k; i++) {
            if (!dfs(nums, sum / k, 0, used))
                return false;
        }
        
        return true;
    }

private:
    bool dfs(vector<int> &nums, int target, int pos, vector<bool> &used) {
        if (pos == nums.size()) 
            return false;
        if (used[pos] || nums[pos] > target) 
            return dfs(nums, target, pos + 1, used);
        if (nums[pos] == target) {
            used[pos] = true;
            return true;
        }
        for (; pos < nums.size(); pos++) {
            if (used[pos]) continue;
            if (dfs(nums, target - nums[pos], pos + 1, used)) {
                used[pos] = true;
                return true;
            }
        }
        return false;
    }
};