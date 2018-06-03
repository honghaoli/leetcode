/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// Greedy Algorithm:
// sort the intervals by the end time.
// then from the start, greedy select the smallest end time as the non-overlapping intervals.
// Proof: If we have a max subset of non-overlapping intervals, 
//          and there is another interval with smaller end time than the first one, 
//          we could always replace the first interval with this one.
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto cmp = [](const Interval &v1, const Interval &v2) { return v1.end < v2.end; };
        sort(intervals.begin(), intervals.end(), cmp);
        int last_end = INT_MIN;
        int num_subsets = 0;
        for (auto &v : intervals) {
            if (v.start >= last_end) {
                ++num_subsets;
                last_end = v.end;
            }
        }
        return intervals.size() - num_subsets;
    }
};
