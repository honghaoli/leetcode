// solution 2
// Stack
// time O(N), space O(N + M)
// N, total temperature data;
// M, total allowed temperature value;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk;         // pair of (id, temperature)
        vector<int> result(temperatures.size(), 0);
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (!stk.empty() && stk.top().second <= temperatures[i]) {
                stk.pop();
            }
            if (stk.empty()) {
                result[i] = 0;
            } else {
                result[i] = stk.top().first - i;
            }
            stk.push({i, temperatures[i]});
        }
        return result;
    }
};



// solution 1
// Bucket sort
// time O(NM), space O(N + M)
// N, total temperature data;
// M, total allowed temperature value;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int highest = 101;
        vector<int> bucket(highest, INT_MAX);
        int max_temp = 0;
        vector<int> result(temperatures.size(), 0);
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            if (max_temp <= temperatures[i]) {
                result[i] = 0;
            } else {
                int id = INT_MAX;
                for (int t = temperatures[i] + 1; t <= max_temp; ++t) {
                    id = min(id, bucket[t]);
                }
                result[i] = id - i;
            }
            bucket[temperatures[i]] = i;
            max_temp = max(max_temp, temperatures[i]);
        }

        return result;
    }
};
