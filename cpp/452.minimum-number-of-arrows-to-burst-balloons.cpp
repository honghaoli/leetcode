// A straight forward greedy algorithm:
// First sort all the intervals by it's starting point, if start1 == start2, then sort by ending point.
// Then we calculate the overlapped interval between previous intervals.
// If the previous interval has no overlap for current interval, that's the time we need another array, so we increase num by 1.
// It is O(NlogN) sort + O(N) sweep algorithm, O(1) extra space.
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.size() <= 1) return points.size();

        sort(points.begin(), points.end());

        int num = 1;
        pair<int, int> interval{INT_MIN, INT_MAX};      // overlapping interval for all previous balloons
        for (auto &p : points) {
            interval.first = max(interval.first, p.first);
            interval.second = min(interval.second, p.second);
            if (interval.first > interval.second) {
                num++;
                interval = p;
            }
        }
        return num;
    }
};
