// pair (d, n): distance int d, with n points in it, average dist = d / (n + 1)
// maintain in ordered set, ordered by float(d / (n + 1))
// everytime choose the max one, add one more point into it.
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int min_pos = INT_MAX;
        int max_pos = INT_MIN;
        for (int i = 0; i < stations.size(); ++i) {
            min_pos = min(min_pos, stations[i]);
            max_pos = max(max_pos, stations[i]);
        }
        double maxInterval = 1.0 * (max_pos - min_pos) / (K + 1.0);

        auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2) {
            return p1.first * 1.0 / (p1.second + 1.0) > p2.first * 1.0 / (p2.second + 1.0);
        };
        multiset<pair<int, int>, decltype(cmp)> maxDist(cmp);   // must use multiset, in case duplicate same interval.
        for (int i = 1; i < stations.size(); ++i) {
            int interval = stations[i] - stations[i - 1];
            int k = static_cast<int>(1.0 * interval / maxInterval - 1.0);
            k = max(k, 0);
            K -= k;
            maxDist.insert({interval, k});
        }
        // add points to the max distance place
        while (K > 0) {
            auto it1 = maxDist.begin();        // the largest
            auto it2 = ++maxDist.begin();     // the 2nd largest
            // add k points to make the max distance smaller than the 2nd largest
            int k = static_cast<int>(1.0 * it1->first * (it2->second + 1.0) / it2->first - it1->second - 1.0);
            // at least 1 point, at most add K points.
            if (k < 1) {
                k = 1;
            } else if (k > K) {
                k = K;
            }
            // cout << it1->first << ": " <<  k << endl;
            // for (auto iter = maxDist.begin(); iter != maxDist.end(); ++iter) {
                // cout << iter->first << ", " << iter->second << " | ";
            // }
            // cout << endl;
            K -= k;
            pair<int, int> newPair{it1->first, it1->second + k};
            maxDist.erase(it1);
            maxDist.insert(newPair);
        }
        //
        auto it = maxDist.begin();        // the largest
        return it->first * 1.0 / (it->second + 1.0);
    }
    
};