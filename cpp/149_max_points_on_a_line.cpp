// MUST use long double to pass the test case
//  [[0,0],[94911151,94911150],[94911152,94911151]]

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2)
            return points.size();
        
        int maxnum = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<long double, int> hash;
            int duplicate = 0;
            int max_current = 1;
            for (int j = i+1; j < points.size(); j++) {
                int dx = points[i].x - points[j].x;
                int dy = points[i].y - points[j].y;
                if (dx == 0 && dy == 0) {
                    duplicate++;
                    continue;
                }
                long double slope = (dx == 0)? std::numeric_limits<long double>::max() : static_cast<long double>(dy) / static_cast<long double>(dx);
                hash[slope] = (hash[slope] == 0) ? 2 : hash[slope] + 1;
                if (hash[slope] > max_current)
                    max_current = hash[slope];
            }
            max_current += duplicate;
            if (max_current > maxnum)
                maxnum = max_current;
        }
        return maxnum;
    }
};
