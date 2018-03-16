class Solution {
public:
    // the number: n =  X X X X X
    // digit index:     4 3 2 1 0th 
    // the number of 1s as in the ith digit is:
    // num_i = n / 10^(i + 1) * 10^i + [if (n_{i-1} > 1), 10^i; if (==1), n % 10^i + 1, if (< 1), 0];
    // the 1st 'if' is when you have  2X, so 10, 11, 12... 19, there are 10 numbers;
    // the 2nd 'if' is when you have  15, so 10, 11, 12...15, there are 5 + 1 numbers;
    // the 3rd 'if' is when you have  08, so no numbers;
    // for example:  1206
    // 0th digit = 120 *    1 + (6 > 1) * 1          = 121;
    // 1th digit =  12 *   10 + (0 < 1) * 0          = 120;
    // 2th digit =   1 *  100 + (2 > 1) * 100        = 200;
    // 3rd digit =   0 * 1000 + (1 == 1) * (206 + 1) = 207;
    // so the total = 648
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        // num of 1 as in the 0th digit
        int sum = 0;
        // must use long here, consider the INT_MAX, you need a larger number than that.
        long k = 1;
        while (n >= k) {
            // the first part of the formula
            sum += (n / (k * 10)) * k;
            // in the second 'if', m = n % 10^i
            int m = n % k;
            // d is n_{i - 1}
            int d = (n % (k * 10)) / k;
            if (d > 1)  // 1st 'if'
                sum += k;
            else if (d == 1) // 2nd 'if'
                sum += m + 1;
            k *= 10;
        }
        return sum;
    }
};


