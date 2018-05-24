class Solution {
public:
    int integerBreak(int n) {
        int max_ = 0;
        for (int i = 2; i <= n / 2; i++) {
            int num1 = n / i;
            int num2 = n / i + 1;
            int count2 = n - (num1 * i);
            int count1 = i - count2;
            int multiply = pow(num1, count1) * pow(num2, count2);
            if (multiply > max_) max_ = multiply;
            else break;
        }
        return max_;
    }
};
