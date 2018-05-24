class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        neighbors = vector<vector<int>>(numCourses, vector<int>());
        for (auto &p : prerequisites) {
            neighbors[p.second].push_back(p.first);       // pre -> course
        }
        // dfs
        visited = vector<bool>(numCourses, false);
        onStack = vector<bool>(numCourses, false);    // check loop for dfs
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i])
                dfs(i);
        }
        //
        return !hasCycle;
    }

private:
    vector<vector<int>> neighbors;
    vector<bool> visited;
    vector<bool> onStack;    // check loop for dfs
    bool hasCycle = false;

    void dfs(int i) {
        onStack[i] = true;
        visited[i] = true;
        for (int n : neighbors[i]) {
            if (onStack[n]) {
                hasCycle = true;
                return;
            } else if (!visited[n]) {
                dfs(n);
            }
        }
        onStack[i] = false;
    }
};

