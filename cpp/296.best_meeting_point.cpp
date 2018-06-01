class Solution {
public:
    // brute force, O(N^2), for each point, calculate the distance from all 1 points.
    // For Euler distance: sqrt sum(xi - x)^2
    // using math, the best location (x, y) is (average all xi, average all yi).
    // For Manhattan distance: sum abs(xi - x)
    // the best location(x, y) is the median?
    int minTotalDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return -1;
        int m = grid[0].size();
        if (m == 0) return -1;

        int num = 0;
        vector<int> nx(n, 0);
        vector<int> ny(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    num++;
                    nx[i]++;
                    ny[j]++;
                }
            }
        }
        int median = num / 2 + 1;
        // find median point
        int x, y;
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp += nx[i];
            if (tmp >= median) {
                x = i;
                break;
            }
        }
        tmp = 0;
        for (int i = 0; i < m; i++) {
            tmp += ny[i];
            if (tmp >= median) {
                y = i;
                break;
            }
        }
        cout << x << ", " << y << endl;
        // calculate distance;
        int distx = 0;
        for (int i = 0; i < n; i++) {
            distx += nx[i] * abs(i - x);
        }
        int disty = 0;
        for (int i = 0; i < m; i++) {
            disty += ny[i] * abs(i - y);
        }
        return distx + disty;
    }
};