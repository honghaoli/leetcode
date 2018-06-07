// use 4 matrix: left, right, up, down to record:
// from [i][j], move 4 direction, will end at which position.
// O(nm) for this step.
// then start from the start, DFS/BFS to find next position, mark as visited.
// until find the destiny or visit all.
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        N = maze.size();
        if (N == 0) return false;
        M = maze[0].size();
        if (M == 0) return false;

        buildGraph(maze);

        visited = vector<vector<bool>>(N, vector<bool>(M, false));

        pair<int, int> start_ = {start[0], start[1]};
        pair<int, int> end_ = {destination[0], destination[1]};

        return dfs(start_, end_);
    }

private:
    int N, M;
    vector<vector<pair<int, int>>> left, right, up, down;
    vector<vector<bool>> visited;

    void buildGraph(vector<vector<int>> &maze) {
        left = vector<vector<pair<int, int>>>(N, vector<pair<int, int>>(M, {0, 0}));
        right = vector<vector<pair<int, int>>>(N, vector<pair<int, int>>(M, {0, 0}));
        up = vector<vector<pair<int, int>>>(N, vector<pair<int, int>>(M, {0, 0}));
        down = vector<vector<pair<int, int>>>(N, vector<pair<int, int>>(M, {0, 0}));

        for (int i = 0; i < N; ++i) {
            // from left to right;
            int l = 0;      // stop at left most place
            for (int j = 0; j < M; ++j) {
                if (maze[i][j] == 1) l = j + 1;
                left[i][j] = {i, l};
            }
            // from right to left;
            int r = M - 1;      // stop at right most place
            for (int j = M - 1; j >= 0; --j) {
                if (maze[i][j] == 1) r = j - 1;
                right[i][j] = {i, r};
            }
        }

        for (int j = 0; j < M; ++j) {
            // from up to down;
            int u = 0;      // stop at upper most place
            for (int i = 0; i < N; ++i) {
                if (maze[i][j] == 1) u = i + 1;
                up[i][j] = {u, j};
            }
            // from down to up;
            int d = N - 1;      // stop at upper most place
            for (int i = N - 1; i >= 0; --i) {
                if (maze[i][j] == 1) d = i - 1;
                down[i][j] = {d, j};
            }
        }
    }

    bool dfs(pair<int, int> &start, pair<int, int> &end) {
        // cout << "visit: " << start.first << ", " << start.second << endl;
        if (start == end) return true;
        visited[start.first][start.second] = true;
        auto &l = left[start.first][start.second];
        auto &r = right[start.first][start.second];
        auto &u = up[start.first][start.second];
        auto &d = down[start.first][start.second];
        for (auto next : {l, r, u, d}) {
            if (visited[next.first][next.second]) continue;
            if (dfs(next, end)) return true;
        }
        return false;
    }
};