class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int mid, insert;
        while (start <= end) {
            mid = (start + end) / 2;
            if ( nums[mid] > target) {
                end = mid - 1;
                insert = mid;
                continue;
            } else if (nums[mid] < target) {
                start = mid + 1;
                insert = mid + 1;
                continue;
            } else {
                return mid;
            }
        }

        return insert;
    }
};





// concise

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if ( nums[mid] > target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                return mid;
            }
        }

        return start;
    }
};
