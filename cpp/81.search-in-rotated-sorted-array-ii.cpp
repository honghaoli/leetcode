// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         int n = nums.size();
//         if (n < 1) return false;
//         if (n < 2) return target == nums[0];
//         if (nums[0] < nums[n - 1]) return binarySearch(nums, target, 0, n - 1);

//         // now it must be rotated
//         return searchRange(nums, target, 0, n - 1);
//     }


// private:

//     bool searchRange(vector<int> &nums, int target, int lo, int hi) {
//         if (lo > hi) return false;

//         int mid = (hi - lo) / 2 + lo;
//         if (target == nums[mid]) return true;

//         // we cannot decide which part might contain the target
//         if (nums[lo] == nums[mid] && nums[hi] == nums[mid]) {
//             return searchRange(nums, target, mid + 1, hi) || searchRange(nums, target, lo, mid - 1);
//         } else if (nums[mid] > nums[hi]) {
//             // if mid in first part
//             if (target > nums[mid] || target < nums[lo]) {
//                 return searchRange(nums, target, mid + 1, hi);
//             } else {
//                 return binarySearch(nums, target, lo, mid - 1);
//             }
//         } else {
//             // now, mid must in the 2nd part
//             if (target < nums[mid] || target > nums[hi]) {
//                 return searchRange(nums, target, lo, mid - 1);
//             } else {
//                 return binarySearch(nums, target, mid + 1, hi);
//             }
//         }
//     }

//     bool binarySearch(vector<int> &nums, int target, int lo, int hi) {
//         if (lo > hi) return false;
//         int mid = (hi - lo) / 2 + lo;
//         if (target == nums[mid]) {
//             return true;
//         } else if (target > nums[mid]) {
//             return binarySearch(nums, target, mid + 1, hi);
//         } else {
//             return binarySearch(nums, target, lo, mid - 1);
//         }
//     }
// };


// more concise version
// inspired by the discussion
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() < 1) return false;

        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            if (target == nums[mid]) return true;
            if (nums[mid] > nums[hi]) {
                // mid in the first part.
                if (target > nums[mid] || target < nums[lo]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            } else if (nums[mid] < nums[hi]) {
                // mid in the 2nd part.
                if (target < nums[mid] || target > nums[hi]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                // mid == hi, dont know which part now, so remove hi one by one
                hi--;
            }
        }

        return false;
    }
};