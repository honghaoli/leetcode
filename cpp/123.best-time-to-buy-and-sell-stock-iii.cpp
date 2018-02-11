class Solution {
public:
    // O(n) time, O(n) space
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;

        vector<int> first(n, 0);
        int low = prices[0];
        int maxp = 0;
        for (int end = 0; end < n; end++) {
            maxp = max(maxp, prices[end] - low);
            low = min(low, prices[end]);
            first[end] = maxp;
        }
        
        vector<int> second(n, 0);
        int high = prices[n - 1];
        maxp = 0;
        for (int start = n - 1; start >= 0; start--) {
            maxp = max(maxp, high - prices[start]);
            high = max(high, prices[start]);
            second[start] = maxp;
        }
        
        maxp = max(first[n - 1], second[0]);
        for (int cut = 1; cut < n; cut++) {
            maxp = max(maxp, first[cut - 1] + second[cut]);
        }
        
        return maxp;
    }
};