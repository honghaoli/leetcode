class Graph {
public:
    void addVertex(char v) {
        V.insert(v);
    }
    
    void addEdge(char from, char to) {
        if (from != to) {
            E[from].insert(to);
        }
    }

    void topologicalSort() {
        visited.clear();
        onStack.clear();
        order.clear();
        for (auto c : V) {
            if (visited.count(c) == 0) {
                // not visited
                dfs(c);
                if (hasCycle) return;
            }
        }
    }

    string sortResult() {
        if (hasCycle) return "";
        reverse(order.begin(), order.end());
        return order;
    }

private:
    bool hasCycle = false;
    string order;
    unordered_set<char> V;
    unordered_set<char> visited;
    unordered_set<char> onStack;
    unordered_map<char, unordered_set<char>> E;

    void dfs(char c) {
        visited.insert(c);
        onStack.insert(c);
        for (char n : E[c]) {
            if (onStack.count(n) != 0) {
                hasCycle = true;
                return;
            } else if (visited.count(n) == 0) {
                // not visited
                dfs(n);
            }
        }
        onStack.erase(c);
        order.push_back(c);
    }
};


class Solution {
public:
    string alienOrder(vector<string>& words) {
        Graph G = Graph();
        buildVertices(G, words);
        buildGraph(G, words);
        G.topologicalSort();
        return G.sortResult();
    }


private:
    void buildVertices(Graph &G, vector<string> &words) {
        for (auto &s : words) {
            for (auto &c : s) {
                G.addVertex(c);
            }
        }
    }
    
    void buildGraph(Graph &G, vector<string> &words) {
        for (int i = 0; i < words.size() - 1; i++) {
            int len = min(words[i].size(), words[i + 1].size());
            for (int j = 0; j < len; j++) {
                char c1 = words[i][j];
                char c2 = words[i + 1][j];
                if (c2 != c1) {
                    G.addEdge(c1, c2);
                    break;
                }
            }
        }
    }
};