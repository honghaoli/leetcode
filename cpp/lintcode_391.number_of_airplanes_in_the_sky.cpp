/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */

class Solution {
public:
    /**
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    // sort the start time and end time separately;
    // for each start time, add the number; for each end time, deduct the number.
    int countOfAirplanes(vector<Interval> &airplanes) {
        vector<int> starts, ends;
        for (auto &interval : airplanes) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int i = 0, j = 0;
        int num = 0;
        int max_num = 0;
        while (i < starts.size()) {
            if (starts[i] < ends[j]) {
                num++;
                i++;
            } else if (starts[i] > ends[j]) {
                num--;
                j++;
            } else {
                i++;
                j++;
            }
            max_num = max(max_num, num);
        }
        return max_num;
    }
};