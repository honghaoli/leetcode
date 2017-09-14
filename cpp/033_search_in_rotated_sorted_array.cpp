class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        if (hi < 0)
            return -1;
        
        int mid;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            
            int num = nums[mid];
            int nl = nums[lo];
            int nh = nums[hi];
            if (num == target)
                return mid;
            
            // standard binary search if the subarray is sorted.
            if (nl <= nh) {
                if (target < num) {
                    hi = mid - 1;
                    continue;
                }
                if (target > num) {
                    lo = mid + 1;
                    continue;
                }
            }
            
            // the sub array is rotated, nl > nh;
            if (num >= nl) {
                if (target < num && target >= nl) {
                    hi = mid - 1;
                    continue;
                } else {
                    lo = mid + 1;
                    continue;
                }
            }
            
            if (num <= nh) {
                if (target <= nh && target > num) {
                    lo = mid + 1;
                    continue;
                } else {
                    hi = mid - 1;
                    continue;
                }
            }
        }
        
        return -1;
    }
};









// more concise one
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        if (hi < 0)
            return -1;
        
        int mid;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            
            int num = nums[mid];
            int nl = nums[lo];
            int nh = nums[hi];
            if (num == target)
                return mid;
            
            if (num >= nl) {
                if (target >= nl && target < num) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                if (target > num && target <= nh) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        
        return -1;
    }
};






