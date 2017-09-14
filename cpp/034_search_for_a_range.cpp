class Solution {
public:
    // solution 1.0
    // find the first index and last index separately
    // two binary search combined.
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = searchFirst(nums, target);
        int last = searchLast(nums, target);
        return vector<int>{first, last};
    }
    
    int searchFirst(vector<int> &nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int mid;
        while (lo <= hi) {
            mid = (hi - lo) / 2 + lo;
            if (target == nums[mid] && (mid == 0 || nums[mid - 1] < target) )
                return mid;
            
            if (target < nums[mid] || (target == nums[mid] && target == nums[mid - 1])) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return -1;
    }
    
    
    int searchLast(vector<int> &nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int mid;
        while (lo <= hi) {
            mid = (hi - lo) / 2 + lo;
            if (target == nums[mid] && (mid == nums.size() - 1 || nums[mid + 1] > target) )
                return mid;
            
            if (target > nums[mid] || (target == nums[mid] && target == nums[mid + 1])) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return -1;
    }
};
