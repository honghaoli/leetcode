class Graph {
public:
    void addVertex(char v) {
        V.insert(v);
    }
    
    void addEdge(char from, char to) {
        //V.insert(from);
        //V.insert(to);
        if (from != to) {
            E[from].insert(to);
            cout << from << " -> " << to << endl;            
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
        buildGraph(G, words, 0, words.size() - 1, 0);
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
    
    void buildGraph(Graph &G, vector<string> &words, int start, int end, int index) {
        if (start >= end) return;   // only one word, nothing to compare
        // remove the word if the compared index is the end of the word
        if (index >= words[start].size()) {
            buildGraph(G, words, start + 1, end, index);
            return;
        }
        //
        int i = start;
        char c1 = words[i][index];
        while (++i <= end) {
            char c2 = words[i][index];
            if (c2 != c1) {
                // cout << start << ", " << i << ", " << index << endl;
                G.addEdge(c1, c2);
                buildGraph(G, words, start, i - 1, index + 1);
                start = i;
                break;
            }
        }
        if (i >= end && start < end)
            buildGraph(G, words, start, end, index + 1);
        else
            buildGraph(G, words, start, end, index);


    }
};