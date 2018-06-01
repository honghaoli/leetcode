// If this line exists, then it should be x = average of all x_i points.
// then check if each point has a reflection about this line.
class Solution {
public:
    // NOTE: test case:  points may have duplicates!!!
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.size() <= 1) return true;
        unordered_set<pair<int, int>, pair_hash> hash;
        int sumx = 0, sumy = 0;
        for (auto &p : points) {
            // remove duplicates!!!
            if (hash.count(p) == 0) {
                sumx += p.first;
                sumy += p.second;
                hash.insert(p);
            }
        }
        int num_unique = hash.size();
        // if the line is x = a, then 2a should be integer!
        int a2 = sumx * 2;
        if (a2 % num_unique != 0) return false;
        a2 /= num_unique;   // now a2 = 2a, where the line is x = a
        // for each point, check the reflection point
        for (auto &p : hash) {
            // if not found
            if (hash.count(make_pair(a2 - p.first, p.second)) == 0)
                return false;
        }
        return true;
    }

private:
    // provide hash function for pair<int, int>
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            // Mainly for demonstration purposes, i.e. works but is overly simple
            // In the real world, use sth. like boost.hash_combine
            return h1 ^ (h2 + 1);   // +1 makes (2, 1) and (1, 2) pair not the same hash value.
        }
    };
};