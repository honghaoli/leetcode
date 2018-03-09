// solution 1
// from discussion use deque
// front --- end
// max is at front, every time insert to end, if end is smaller then remove the end until the last is larger than current.
// so the deque is always sorted.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (k > nums.size() || nums.size() < 1) return result; 

        deque<vector<int>> d;
        d.push_back(vector<int>{0, nums[0]});

        int curr = 1;
        while (curr < nums.size()) {
            // remove back smaller number, never have a chance to be max
            while(d.back().at(1) <= nums[curr])
                d.pop_back();
            // remove front if it expires
            if (!d.empty() && d.front().at(0) <= curr - k)
                d.pop_front();
            // add current to the back
            d.push_back(vector<int>{curr, nums[curr]});
            // get current max
            if (curr >= k - 1)
                result.push_back(d.front().at(1));
        }

        return result;
    }
};