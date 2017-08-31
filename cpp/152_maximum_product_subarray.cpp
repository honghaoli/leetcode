class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() < 1)
            return 0;
        
        int max_so_far = nums[0];
        int max_plus_end_here = 0;
        int max_minus_end_here = 0;
        if (nums[0] > 0)
            max_plus_end_here = nums[0];
        else if (nums[0] < 0)
            max_minus_end_here = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 0) {
                max_plus_end_here = 0;
                max_minus_end_here = 0;
                max_so_far = max(max_so_far, 0);
            } else if (nums[i] > 0) {
                max_plus_end_here = max(max_plus_end_here * nums[i], nums[i]);
                max_minus_end_here *= nums[i];
                max_so_far = max(max_so_far, max_plus_end_here);
            } else {
                int tmp = max_plus_end_here * nums[i];
                max_plus_end_here = max_minus_end_here * nums[i];
                max_minus_end_here = min(tmp, nums[i]);              
                max_so_far = max(max_so_far, max_plus_end_here);
            }
        }
        
        return max_so_far;
    }
};
