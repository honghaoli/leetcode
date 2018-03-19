class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        int fromLeft = 1, fromRight = 1;
        for (int i = 0; i < n; i++) {
            result[i] = fromLeft;
            fromLeft *= nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= fromRight;
            fromRight *= nums[i];
        }
        return result;
    }
};
