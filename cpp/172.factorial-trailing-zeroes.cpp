class Solution {
public:
    int trailingZeroes(int n) {
        int k = 5;     
        int num = 0;
        while (k <= n) {
            n /= k;     // safe for overflow
            num += n;
        }
        return num;
    }
};

