class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int buy = prices[0];
        int diff = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] <= buy) {
                buy = prices[i];
            } else {
                if (prices[i] - buy > diff) {
                    diff = prices[i] - buy;
                }
            }
        }

        return diff;
    }
};
