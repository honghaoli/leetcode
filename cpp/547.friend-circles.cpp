
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if (n <= 1) return n;
        vector<bool> visited(n, false);
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            num++;
            bfs(i, M, visited);
        }
        return num;
    }

    void bfs(int i, vector<vector<int>> &M, vector<bool> &visited) {
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int k = q.front();
            q.pop();
            visited[k] = true;
            for (int j = 0; j < M.size(); j++) {
                if (!visited[j] && M[k][j] == 1)
                    q.push(j);
            }
        }
    }
};
