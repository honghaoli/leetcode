class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<vector<int>> parent(edges.size() + 1, vector<int>());
        vector<bool> visited(edges.size() + 1, false);
        vector<int> cycle{-1, -1};
        int id_two_parents = -1;
        for (auto &e : edges) {
            if (visited[e[0]] && visited[e[1]]) 
                cycle = {e[0], e[1]};
            visited[e[0]] = true;
            visited[e[1]] = true;
            parent[e[1]].push_back(e[0]);
            if (parent[e[1]].size() > 1)
                id_two_parents = e[1];
        }
        //
        // cout << id_two_parents << endl;
        // cout << cycle[0] << ", " << cycle[1] << endl;
        if (id_two_parents < 0) {
            // no node has two parents, means a single cycle, any node in this cycle can be root
            // so return the last cycle edge
            return cycle;
        } else {
            // one node has two parents, must remove one edge from there.
            // we recursively find the parent, 
            // if the last node has no parent, that's the root, we should keep this branch
            // otherwise if this branch is cycle, remove this edge.
            int branch0 = parent[id_two_parents][0];
            int branch1 = parent[id_two_parents][1];
            int id = branch0;
            while (parent[id].size() != 0 && parent[id][0] != id_two_parents) {
                // find the root or the cycle
                id = parent[id][0];
            }
            if (parent[id].size() == 0) {
                // parent[id].size() == 0, the root branch, remove the other branch
                return {branch1, id_two_parents};
            } else {
                // this is the cycle branch, remove this branch
                return {branch0, id_two_parents};
            }
        }
    }
};

