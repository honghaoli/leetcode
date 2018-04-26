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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts, ends;
        for (auto &v : intervals) {
            starts.push_back(v.start);
            ends.push_back(v.end);
        }
        //
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        //
        int max_overlap = 0;
        int overlap = 0;
        int i = 0, j = 0;
        while (i < intervals.size()) {
            if (starts[i] < ends[j]) {
                overlap++;
                max_overlap = max(max_overlap, overlap);
                i++;
            } else if (starts[i] > ends[j]) {
                overlap--;
                j++;
            } else {
                i++;
                j++;
            }
        }
        return max_overlap;
    }
};