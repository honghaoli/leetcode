class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum = 0;
        int max_len = 0;
        unordered_map<int, int> hash;      // store all the sum from idx=0 to current indx
        hash[0] = -1;   // if the sum == k, then this subarray is from the start
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (hash.count(sum - k) != 0)
                max_len = max(max_len, i - hash[sum - k]);
            if (hash.count(sum) == 0)   // only store the min index for multiple identical sum.
                hash[sum] = i;
        }
        return max_len;
    }
};