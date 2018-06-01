// pure math problem:
// 1 digits:  0~9 = 10;
// 2 digits: (1~9) * (0~9 -1) = 9 * 9 = 81
// 3 digits: (1~9) * (0~9 -1) * (0~9 - 2) = 9 * 9 * 8
// ...
// 10 digits:  9 * 9 * 8 * ... * 1
// > 10 digits:  0.
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n <= 0) return 1;
        if (n == 1) return 10;
        int num = 81;       // 2 digits: 9 * 9 = 81
        int sum = num;
        for (int i = 3; i <= min(n, 10); i++) {     // at most 10 digits
            num *= 11 - i;
            sum += num;
        }
        return sum;
    }
};