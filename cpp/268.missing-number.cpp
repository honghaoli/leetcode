class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum1 = nums.size() * (nums.size() + 1) / 2;
        int sum2 = 0;
        for (int &n : nums) {
            sum2 += n;
        }
        return sum1 - sum2;
    }
};
