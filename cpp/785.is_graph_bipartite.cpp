static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n <= 2) return true;
        vector<int> colors(n, -1);
        // dfs, to mark colors
        for (int i = 0; i < n; i++) {
            if (colors[i] < 0) {
                bool result = dfs(i, 0, graph, colors);
                if (!result) return false;
            }
        }
        return true;
    }

private:
    bool dfs(int i, int color, vector<vector<int>> &graph, vector<int> &colors) {
        colors[i] = color;
        for (int n : graph[i]) {
            if (colors[n] == color) return false;
            if (colors[n] < 0) {
                bool result = dfs(n, 1 - color, graph, colors);       // color = 1 or 0
                if (!result) return false;
            }
        }
        return true;
    }
};