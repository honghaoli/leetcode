// solution 1;
// bfs in graph, shortest path
// each node in the graph is a game state, represented by the sequence of numbers, e.g. 123450;
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        N = board.size();
        M = board.at(0).size();
        return bfs(board);
    }

private:
    int N, M;
    unordered_set<int> visited;

    int bfs(vector<vector<int>> &board) {
        int start = encode(board);
        int target = 123450;
        queue<pair<int, int>> q;          // (state, step)
        q.push({start, 0});
        while (!q.empty()) {
            int state = q.front().first;
            int step = q.front().second;
            // cout << "visit: " << state << endl;
            if (target == state) return step;
            q.pop();
            visited.insert(state);
            for (int next : neighbor(state)) {
                if (visited.count(next) != 0) continue;
                q.push({next, step + 1});
            }
        }
        // not found
        return -1;
    }

    const vector<vector<int>> dxy = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<int> neighbor(int state) {
        vector<vector<int>> board = decode(state);
        vector<int> pos0(2, 0);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (board[i][j] == 0)
                    pos0 = {i, j};
            }
        }
        vector<int> result;
        for (int i = 0; i < dxy.size(); ++i) {
            int x = dxy[i][0] + pos0[0];
            int y = dxy[i][1] + pos0[1];
            if (x >= 0 && x < N && y >= 0 && y < M) {
                auto copy = board;
                swap(copy[pos0[0]][pos0[1]], copy[x][y]);
                result.push_back(encode(copy));
            }
        }
        return result;
    }

    int encode(vector<vector<int>> &board) {
        int result = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                result = result * 10 + board[i][j];
            }
        }
        return result;
    }

    vector<vector<int>> decode(int state) {
        vector<vector<int>> board(N, vector<int>(M, 0));
        for (int i = N - 1; i >= 0; --i) {
            for (int j = M - 1; j >= 0; --j) {
                board[i][j] = state % 10;
                state /= 10;
            }
        }
        return board;
    }
};
