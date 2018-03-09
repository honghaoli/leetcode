struct Site {
    int val, i, j;
    Site(int val, int i, int j) : val(val), i(i), j(j) {}
};


class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        if (n < 3) return 0;
        int m = heightMap[0].size();
        if (m < 3) return 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        auto cmp = [](Site &s1, Site &s2) { return s1.val > s2.val; };
        priority_queue<Site, vector<Site>, decltype(cmp)> minHeap(cmp);
        for (int i = 0; i < n; i++) {
            minHeap.push(Site(heightMap[i][0], i, 0));      // left boundary
            minHeap.push(Site(heightMap[i][m - 1], i, m - 1));  // right boundary
            visited[i][0] = true;
            visited[i][m - 1] = true;
        }
        for (int j = 1; j < m - 1; j++) {
            minHeap.push(Site(heightMap[0][j], 0, j));      // upper boundary
            minHeap.push(Site(heightMap[n - 1][j], n - 1, j));  // bottom boundary
            visited[0][j] = true;
            visited[n - 1][j] = true;
        }
        int lowest = minHeap.top().val;     // lowest brick of the boundary

        int volume = 0;
        vector<int> dx{0, 1, 0, -1};
        vector<int> dy{1, 0, -1, 0};
        // shrink the boundary
        while (!minHeap.empty()) {
            Site s = minHeap.top();
            minHeap.pop();
            lowest = max(lowest, s.val);
            for (int k = 0; k < 4; k++) {
                int i = s.i + dx[k];
                int j = s.j + dy[k];
                if (i >= 0 && i < n && j >= 0 && j < m && !visited[i][j]) {
                    if (heightMap[i][j] < lowest)
                        volume += lowest - heightMap[i][j];
                    minHeap.push(Site(heightMap[i][j], i, j));
                    visited[i][j] = true;
                }
            }
        }

        return volume;
    }
};
