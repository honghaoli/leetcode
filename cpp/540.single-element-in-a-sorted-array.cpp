class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) throw;
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
        int lo = 1, hi = n - 2;
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            if (nums[mid] == nums[mid + 1]) {
                if (mid % 2 == 0)
                    lo = mid + 2;
                else 
                    hi = mid - 1;
            } else if (nums[mid] == nums[mid - 1]) {
                if (mid % 2 == 0)
                    hi = mid - 2;
                else 
                    lo = mid + 1;
            } else {
                return nums[mid];
            }
        }
        // never happen
        throw;
    }
};
