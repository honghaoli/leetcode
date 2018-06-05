class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        long lo = lower, hi = upper;
        for (long num : nums) {
            if (num > lo) {
                result.push_back(convert(lo, num - 1));
            }
            lo = num + 1;
        }
        // tail
        if (lo <= hi) {
            result.push_back(convert(lo, hi));
        }
        return result;
    }

private:
    string convert(long lo, long hi) {
        string result = to_string(lo);
        if (hi != lo) {
            result += "->";
            result += to_string(hi);
        }
        return result;
    }
};