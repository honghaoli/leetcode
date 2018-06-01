// thought 1: first check the connectivity of all 1s, if not connected, no way to build, return -1.
// use bfs to spread from one 1, see how many 1 can be reached.

// thought 2: for each 0, bfs search and calculate all the distance to 1s, if some 1s dist = infinite while other dist = finite, then it's not connected.
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        N = grid.size();
        if (N == 0) return -1;
        M = grid[0].size();
        if (M == 0) return -1;

        counts = count_012(grid);
        // cout << counts[0] << ", " << counts[1] << ", " << counts[2] << endl;
        if (counts[0] == 0) return -1;

        marker = 0;
        // for each 0, bfs to find all distance.
        int dist = INT_MAX;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 0) {
                    int tmp = distance(grid, i, j);
                    // cout << i << ", " << j << ": " << tmp << endl;
                    if (tmp == -1) return -1;      // not connected!
                    dist = min(dist, tmp);
                }
            }
        }

        return dist == INT_MAX ? -1 : dist;
    }

private:
    int N, M;
    int marker;     // represents the empty space, avoid duplicating the grid everytime.
    vector<int> counts;

    vector<int> count_012(vector<vector<int>> &grid) {
        vector<int> counts(3, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                counts[grid[i][j]]++;
            }
        }
        return counts;
    }

    struct Point {
        Point() = delete;
        Point(int dist, int i, int j) : dist(dist), i(i), j(j) {}
        int dist, i, j;
    };

    const vector<int> dx {-1, 0, 1, 0};
    const vector<int> dy {0, -1, 0, 1};
    // return -1 if not connected
    // return INT_MAX none 1 is reachable
    int distance(vector<vector<int>> &grid, int i, int j) {
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        queue<Point> q;
        q.push(Point(0, i, j));
        visited[i][j] = true;
        int total_distance = 0;
        int count_reached_1 = 0;
        int dist = 0;
        while (!q.empty()) {
            Point p = q.front();
            q.pop();
            // cout << "visit: " << dp.i << ", " << dp.j << endl;
            for (int k = 0; k < 4; k++) {
                int x = p.i + dx[k];
                int y = p.j + dy[k];
                if (x >= 0 && x < N && y >= 0 && y < M && !visited[x][y]) {
                    // cout << "neigh: " << x << ", " << y << endl;
                    if (grid[x][y] == 1) {
                        total_distance += p.dist + 1;
                        count_reached_1++;
                    } else if (grid[x][y] == marker) {
                        q.push(Point(p.dist + 1, x, y));
                    }
                    visited[x][y] = true;
                }
            }
        }
        // This following line is wrong!!!
        // if (count_reached_1 != 0 && count_reached_1 != counts[1]) return -1;    // two parts of 1s, some reachable while other not!
        if (count_reached_1 != counts[1]) return INT_MAX;    // not all 1s are reachable from here.
        return total_distance;
    }
};