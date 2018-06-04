// straight forward Union-Find algorithm.
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> &pairs) {
        int n1 = words1.size();
        int n2 = words2.size();
        if (n1 != n2) return false;

        unionFind(pairs);

        for (int i = 0; i < n1; ++i) {
            if (!isSimilar(words1[i], words2[i])) return false;
        }
        return true;
    }

private:
    unordered_map<string, string> parent;
    unordered_map<string, int> size;

    void unionFind(vector<pair<string, string>> &pairs) {
        for (auto &p : pairs) {
            connect(p.first, p.second);
        }
    }

    // find
    bool isSimilar(string &w1, string &w2) {
        // simply identical!
        if (w1 == w2) return true;
        // if not found in pairs
        if (parent.count(w1) == 0 || parent.count(w2) == 0)
            return false;
        // else find in connectivity
        return root(w1) == root(w2);
    }

    // union
    void connect(string &w1, string &w2) {
        // for new insert word
        if (parent.count(w1) == 0) {
            parent[w1] = w1;
            size[w1] = 1;
        }
        if (parent.count(w2) == 0) {
            parent[w2] = w2;
            size[w2] = 1;
        }
        // connect
        string r1 = root(w1);
        string r2 = root(w2);
        if (size[r1] <= size[r2]) {
            parent[r1] = r2;
            size[r2] += size[r1];
        } else {
            parent[r2] = r1;
            size[r1] += size[r2];
        }
    }

    string root(string w1) {
        while (parent[w1] != w1) {
            parent[w1] = parent[parent[w1]];    // flatten tree, compression
            w1 = parent[w1];
        }
        return w1;
    }

};