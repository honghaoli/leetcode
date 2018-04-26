class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        // n >= 2
        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;
        //
        return bs(nums, 1, n - 2);
    }

private:
    int bs(vector<int> &nums, int lo, int hi) {
        int mid = (hi - lo) / 2 + lo;
        if (nums[mid + 1] >= nums[mid])
            return bs(nums, mid + 1, hi);
        else if (nums[mid - 1] >= nums[mid])
            return bs(nums, lo,  mid - 1);
        else 
            return mid;
    }
};
