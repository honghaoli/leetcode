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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() <= 1) 
            return true;
        auto cmp = [](Interval &i1, Interval &i2) { return i1.start < i2.start; };
        sort(intervals.begin(), intervals.end(), cmp);
        int end = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < end)
                return false;
            end = intervals[i].end;
        }
        return true;
    }
};