class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result{};
        std::sort(nums.begin(), nums.end());
        if (nums.size() < 3)
            return result;
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0)
                break;
            
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int target = -nums[i];
            int start = i + 1;
            int end = nums.size() -1;
            while (start < end) {
                if (start > i + 1 && nums[start] == nums[start-1]) {
                    start++;
                    continue;
                }
                
                if (nums[start] + nums[end] > target) {
                    end--;
                } else if (nums[start] + nums[end] < target) {
                    start++;
                } else {
                    result.push_back(vector<int>{nums[i], nums[start], nums[end]});
                    start++;
                }
            }
            
       
        }
        return result;
    }
};
