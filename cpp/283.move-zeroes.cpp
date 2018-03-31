class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int n = nums.size();
       if (n == 0) return;
       int i = 0, j = 0;
       while (j < n) {
           if (nums[j] != 0) {
               swap(nums[i], nums[j]);
               j++;
               i++;
           } else {
               j++;
           }
       } 
    }
};
