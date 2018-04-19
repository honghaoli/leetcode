// lol: this is the most important part to make your runtime beats others!
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // p0, profit with 0 stock at hand;
        // p1, profit with 1 stock at hand.
        int p0 = 0, p1 = INT_MIN;
        for (int &p : prices) {
            int tmp = p0;
            p0 = max(p0, p1 + p);
            p1 = max(p1, tmp - p - fee);
        }
        return p0;
    }
};


