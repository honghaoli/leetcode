class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        // find the first collision point
        while (slow != fast || slow == 0) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // find the 2nd collision
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
