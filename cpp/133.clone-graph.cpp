/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;  
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) return nullptr;
        if (hash.count(node) == 0) {
            hash[node] = new UndirectedGraphNode(node->label);
            for (auto n : node->neighbors) {
                hash[node]->neighbors.push_back(cloneGraph(n));
            }
        }
        return hash[node];
    }
};