
// more concise solution
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if (n <= 1) return n;
        // override the sort for pair<int, int> comparator
        // Sort the array. Ascend on width and descend on height if width are same.
        // ref: https://leetcode.com/problems/russian-doll-envelopes/discuss/82763/Java-NLogN-Solution-with-Explanation
        auto cmp = [](pair<int, int> a, pair<int, int> b){
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        };
        sort(envelopes.begin(), envelopes.end(), cmp);       // pair has its own comparator. 

        // LIS problem, the only difference is the comparator
        vector<int> dp;     // store second int of pair
        // https://leetcode.com/problems/russian-doll-envelopes/discuss/82808/C++-9-line-Short-and-Clean-O(nlogn)-solution-(plus-classic-O(n2)-dp-solution).
        for (auto &e : envelopes) {
            // binary search, find the longest ss, with the last number < current number
            auto iter = lower_bound(dp.begin(), dp.end(), e.second);
            // now lo - 1 is the longest ss, with the last number < current number
            // and the new length = lo
            if (iter == dp.end())
                dp.push_back(e.second);
            else if (*iter > e.second)
                *iter = e.second;
        }
        //
        return dp.size();
    }
};





// using LIS: longest increasing subsequence
// for example: https://leetcode.com/problems/longest-increasing-subsequence/description/
// time O(n log n)
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if (n <= 1) return n;
        // override the sort for pair<int, int> comparator
        // Sort the array. Ascend on width and descend on height if width are same.
        // ref: https://leetcode.com/problems/russian-doll-envelopes/discuss/82763/Java-NLogN-Solution-with-Explanation
        auto cmp = [](pair<int, int> a, pair<int, int> b){
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        };
        sort(envelopes.begin(), envelopes.end(), cmp);       // pair has its own comparator. 

        // LIS problem, the only difference is the comparator
        // implementation please refer: https://leetcode.com/submissions/detail/156272502/ or https://en.wikipedia.org/wiki/Longest_increasing_subsequence
        vector<int> M(n + 1, 0);    // the last number index of length of j subsequence
        vector<int> P(n, 0);    // parent node
        int L = 0;  // max length
        for (int i = 0; i < n; i++) {
            // binary search, find the longest ss, with the last number < current number
            int lo = 1, hi = L;
            while (lo <= hi) {
                int mid = (hi - lo) / 2 + lo;
                if (smaller(envelopes[M[mid]], envelopes[i]))
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            // now lo - 1 is the longest ss, with the last number < current number
            // and the new length = lo
            M[lo] = i;
            P[i] = M[lo - 1];
            L = max(L, lo);
        }
        //
        return L;
    }

private:
    inline bool smaller(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.first < p2.first && p1.second < p2.second;
    }
};




// // DP: O(n^2) time, O(n) space
// class Solution {
// public:
//     int maxEnvelopes(vector<pair<int, int>>& envelopes) {
//         sort(envelopes.begin(), envelopes.end());       // pair has its own comparator. 
//         int n = envelopes.size();
//         if (n <= 1) return n;
//         vector<int> dp(n, 1);   // dp[i]: the max number of envelopes if the ith envelopes is the last one.  at least we have one.
//         int max_num = 1;
//         for (int end = 0; end < n; end++) {
//             int w1 = envelopes[end].first;
//             int h1 = envelopes[end].second;
//             for (int pre = end - 1; pre >= 0; pre--) {
//                 int w2 = envelopes[pre].first;
//                 int h2 = envelopes[pre].second;
//                 if (w1 > w2 && h1 > h2) {
//                     dp[end] = max(dp[end], dp[pre] + 1);
//                     max_num = max(max_num, dp[end]);
//                 }
//             }
//         }
//         return max_num;
//     }
// };
