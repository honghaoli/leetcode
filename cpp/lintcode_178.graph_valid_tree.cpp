/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example
Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.


*/

class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // use weighted union find algorithm
        vector<int> sz(n, 1);
        comp.clear();
        for (int i = 0; i < n; i++) 
            comp.push_back(i);
        // union
        for (auto &edge : edges) {
            int p = edge.at(0);
            int q = edge.at(1);
            int p_root = find(p);
            int q_root = find(q);
            if (p_root == q_root) return false; // cyclic, not tree
            if (sz[p_root] > sz[q_root]) {
                comp[q_root] = p_root;
                sz[p_root] += sz[q_root];
            } else {
                comp[p_root] = q_root;
                sz[q_root] += sz[p_root];
            }
        }
        // if all the nodes are in the same component
        // there must be a root has size of n
        for (auto &s : sz) {
            if (s == n) return true;
        }
        return false;
    }
    
private:
    vector<int> comp;
    
    int find(int p) {
        while (p != comp[p])
            p = comp[p];
        return p;
    }
};