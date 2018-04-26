/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() <= 1) return intervals;
        vector<Interval> result;
        auto small = [](Interval &i1, Interval &i2) { return i1.start < i2.start; };
        sort(intervals.begin(), intervals.end(), small);
        Interval prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            Interval curr = intervals[i];
            if (curr.start <= prev.end) {
                prev.end = max(curr.end, prev.end);
            } else {
                result.push_back(prev);
                prev = curr;
            }
        }
        
        result.push_back(prev);
        return result;
    }
};