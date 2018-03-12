class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n < 1) return 0;
        int m = costs[0].size();

        for (int i = 1; i < n; i++) {
            for (int c = 0; c < m; c++) {
                int cost = INT_MAX;
                for (int pre = 0; pre < m; pre++) {
                    if (c != pre) {
                        cost = min(cost, costs[i - 1][pre]);
                    }
                }
                costs[i][c] += cost;
            }
        }

        int value = INT_MAX;
        for (int c = 0; c < m; c++) {
            value = min(value, costs[n - 1][c]);
        }
        return value;
    }
};