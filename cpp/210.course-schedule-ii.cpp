class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        neigh = vector<vector<int>>(numCourses, vector<int>());
        for (auto &p : prerequisites) {
            neigh[p.second].push_back(p.first);
        }
        // dfs
        visited = vector<bool>(numCourses, false);
        onStack = vector<bool>(numCourses, false);
        reversePost = vector<int>();
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i])
                dfs(i);
        }
        //
        if (hasCycle)
            return vector<int>();
        reverse(reversePost.begin(), reversePost.end());
        return reversePost;
    }

private:
    vector<vector<int>> neigh;
    vector<bool> visited;
    vector<bool> onStack;
    vector<int> reversePost;
    bool hasCycle = false;

    void dfs(int i) {
        onStack[i] = true;
        visited[i] = true;
        for (int n : neigh[i]) {
            if (onStack[n]) {
                hasCycle = true;
                return;
            } else if (!visited[n]) {
                dfs(n);
            }
        }
        onStack[i] = false;
        reversePost.push_back(i);
    }
};
