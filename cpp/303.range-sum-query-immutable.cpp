class NumArray {
public:
    NumArray(vector<int> nums) {
        sums = vector<int>(nums.size(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            sums[i] = sum;
        }
    }
    
    int sumRange(int i, int j) {
        int result = sums[j];
        if (i > 0)
            result -= sums[i - 1];
        return result;
    }

private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
