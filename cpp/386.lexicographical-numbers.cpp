// lol: this is the most important part to make your runtime beats others!
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // the first is 1.
        int num = 1;
        vector<int> result(n, 1);
        for (int count = 1; count < n; count++) {
            if (10 * num <= n) {
                // if we can add 0 at end, do that
                num *= 10;
            } else if (num % 10 < 9 && num < n) {
                // if possible, increase the last digit
                num++;
            } else {
                // if finished last digit, try the 2nd last digit.
                num /= 10;
                while (num % 10 == 9)
                    num /= 10;
                num++;
            }
            result[count] = num;
        }
        return result;
    }
};


