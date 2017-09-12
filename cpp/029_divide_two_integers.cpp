class Solution {
public:
    int divide(int dividend, int divisor) {
        // overflow, only one case.
        if (dividend == std::numeric_limits<int>::min() && divisor == -1) 
            return std::numeric_limits<int>::max();
        if (divisor == 1)
            return dividend;
        
        int sign = 1;
        long d1 = dividend, d2 = divisor;
        if (dividend < 0) {
            sign *= -1;
            d1 *= -1;
        }
        if (divisor < 0) {
            sign *= -1;
            d2 *= -1;
        }
        // now both are positive
        
        // find the 1st
        long tmp = d2;
        while (tmp < d1) {
            tmp <<= 1;
        }

        
        int result = 0;
        while (tmp >= d2) {
            result <<= 1;
            if (d1 >= tmp) {
                result += 1;
                d1 -= tmp;
            }
            tmp >>= 1;
        }
        
          
        return result * sign ;
    }
};
