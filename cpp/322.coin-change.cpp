class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        min_num = INT_MAX;
        find(coins, amount, 0, 0);
        return min_mum == INT_MAX ? -1 : min_num;
    }

private:
    int min_num;

    void find(vector<int> &coins, int amount, int count, int index) {
        if (amount == 0) {
            min_num = min(min_num, count);
            return;
        }
        if (amount < 0 || index >= coins.size()) return;    // not found
        for (int freq = amount / coins[index]; freq >= 0; freq--) {
            if (count + freq >= min_num) return;        // no need to find
            find(coins, amount - freq * coins[index], count + freq, index + 1);
        }
    }
};
