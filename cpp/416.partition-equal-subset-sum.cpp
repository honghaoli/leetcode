class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2) return false;
        int sum = 0;
        for (auto &n : nums) {
            sum += n;
        }
        if (sum % 2 != 0) return false;
        sort(nums.begin(), nums.end());
        if (nums.back() > sum / 2) return false;

        return dfs(nums, sum / 2, 0, 0);
    }

private:
    bool dfs(vector<int> &nums, int target, int sum, int pos) {
        if (sum == target) return true;
        while (pos < nums.size()) {
            if (sum + nums[pos] > target) break;
            if (dfs(nums, target, sum + nums[pos], pos + 1)) return true;
            int tmp = nums[pos];
            pos++;
            while (pos < nums.size() && nums[pos] == tmp) 
                pos++;
        }
        return false;
    }
};

