class Solution {
public:
    // O(n) time, O(n) space
    // there is also algorithm for O(n) time and O(1) space
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n < 2) return n;
        vector<int> candies(n, 1);
        // from left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        // from right to left
        int sum = candies[n - 1];
        for (int i = n - 2; i >= 0 ; i--) {
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                candies[i] = candies[i + 1] + 1;
            }
            sum += candies[i];
        }
        //
        return sum;
    }
};