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
        
        auto compare = [](Interval &v1, Interval &v2) -> bool { return v1.start < v2.start; };
        sort(intervals.begin(), intervals.end(), compare);
        
        vector<Interval> result;
        int start = intervals[0].start;
        int end = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            Interval &v = intervals[i];
            if (v.start <= end) {
                end = max(end, v.end);
            } else {
                result.push_back(Interval(start, end));
                start = v.start;
                end = v.end;
            }
        }
        // the last interval
        result.push_back(Interval(start, end));            

        return result;
    }
};
