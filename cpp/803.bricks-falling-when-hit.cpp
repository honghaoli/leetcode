static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();


// reverse the hits sequence, then it is a classical union-find problem.
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        if (grid.size() == 0 || grid.at(0).size() == 0) return vector<int>(hits.size(), 0);
        N = grid.size();
        M = grid.at(0).size();
        grid_ = grid;
        // simulate the end of the hits
        for (auto &h : hits) {
            if (grid_[h.at(0)][h.at(1)] == 1) {
                grid_[h.at(0)][h.at(1)] = 0;
            } else {
                h[0] = -1;      // indicates this hits no brick
            }
        }

        size = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
        parent = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>(M + 1, {0, 0}));
        initialize(grid_);
        int num = numBricks();
        // cout << "initial size: "<< num << endl;

        reverse(hits.begin(), hits.end());

        // dynamic connect
        vector<int> result;
        for (auto &h : hits) {
            if (h.at(0) < 0) {  // this hits no bricks, number not change
                result.push_back(0);
            } else {
                pair<int, int> hit {h.at(0), h.at(1)};
                parent[hit.first][hit.second] = {hit.first, hit.second};
                size[hit.first][hit.second] = 1;
                for (auto p : neighbor(hit)) {
                    connect(p, hit);
                }
                // check if the hit point is connected to the roof
                if (hit.first == 0) {
                    connect(roof, hit);
                }
                int new_num = numBricks();
                // cout << "after hit " << hit.first << " " << hit.second << ": " << new_num << endl;
                result.push_back(max(new_num - num - 1, 0));    // if hit not connected to roof, the new_num == num, this should be 0;
                num = new_num;
                grid_[hit.first][hit.second] = 1;
            }
        }
        //
        reverse(result.begin(), result.end());
        return result;
    }

private:
    int N, M;               // size of input grid
    pair<int, int> roof;    // the most left upper brick, the root of all the gird[0][i] 1 bricks
    vector<vector<pair<int, int>>> parent;
    vector<vector<int>> size;
    vector<vector<int>> grid_;

    void initialize(vector<vector<int>> &grid) {
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        // bfs find 
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (visited[i][j] || grid[i][j] == 0) continue;
                size[i][j] = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    pair<int, int> next = q.front();
                    q.pop();
                    visited[next.first][next.second] = true;
                    parent[next.first][next.second] = {i, j};
                    size[i][j]++;
                    for (auto p : neighbor(next)) {
                        if (visited[p.first][p.second]) continue;
                        q.push(p);
                    }
                }
                // cout << "size " << i << " " << j << ": " << size[i][j] << endl;
            }
        }
        // union the top layer, grid[0][j]
        pair<int, int> left = {-1, -1};
        for (int j = 0; j < M; ++j) {
            if (grid[0][j] == 0) continue;
            if (left.first < 0) {
                left = {0, j};
            } else {
                connect(left, make_pair(0, j));
            }
        }
        // make sure the roof is the root of all the [0][j]
        roof = {N, M};
        parent[roof.first][roof.second] = roof;
        if (left.first >= 0) {
            left = root(left);
            parent[left.first][left.second] = roof;
            size[roof.first][roof.second] = size[left.first][left.second];            
        }
    }

    bool inline isConnected(pair<int, int> &p1, pair<int, int> &p2) {
        return root(p1) == root(p2);
    }

    void connect(pair<int, int> p1, pair<int, int> p2) {
        // cout << "connect [" << p1.first << ", " << p1.second << "] and [" << p2.first << ", " << p2.second << "]" << endl;
        auto r1 = root(p1);
        auto r2 = root(p2);
        if (r1 == r2) return;
        if (size[r1.first][r1.second] > size[r2.first][r2.second]) {
            parent[r2.first][r2.second] = r1;
            size[r1.first][r1.second] += size[r2.first][r2.second] ;
        } else {
            parent[r1.first][r1.second] = r2;
            size[r2.first][r2.second] += size[r1.first][r1.second] ;
        }
    }

    pair<int, int> root(pair<int, int> p) {
        while (parent[p.first][p.second] != p) {
            auto tmp = parent[p.first][p.second];
            parent[p.first][p.second] = parent[tmp.first][tmp.second];
            p = tmp;
        }
        return p;
    }

    int numBricks() {
        auto r = root(roof);
        return size[r.first][r.second];
    }

    vector<pair<int, int>> neighbor(pair<int, int> &pos) {
        const vector<int> dx {0, -1, 0, 1};
        const vector<int> dy {-1, 0, 1, 0};
        vector<pair<int, int>> result;
        for (int i = 0; i < 4; ++i) {
            int x = pos.first + dx[i];
            int y = pos.second + dy[i];
            if (x >= 0 && x < N && y >= 0 && y < M && grid_[x][y] == 1)
                result.push_back({x, y});
        }
        return result;
    }
};

