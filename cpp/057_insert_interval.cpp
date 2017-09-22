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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.size() == 0) return {newInterval};
        
        vector<Interval> result;
        int i = 0;
        bool insert = false;
        while (i < intervals.size()) {
            Interval &v = intervals[i];
            if (v.end < newInterval.start) {
                result.push_back(v);
                i++;
            } else if (v.start > newInterval.end) {
                if (!insert) {
                    result.push_back(newInterval);
                    insert = true;
                }
                result.push_back(v);
                i++;
            } else {
                int start = min(v.start, newInterval.start);
                int end = max(v.end, newInterval.end);
                int j = i + 1;
                while (j < intervals.size() && intervals[j].start <= newInterval.end) {
                    end = max(end, intervals[j].end);
                    j++;
                }
                result.push_back(Interval(start, end));
                i = j;
                insert = true;
            }
        }
        
        // in case it is the biggest.
        if (!insert)
            result.push_back(newInterval);
        
        return result;
    }
};
