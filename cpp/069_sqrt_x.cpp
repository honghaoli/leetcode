class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = x;
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            long m1 = static_cast<long> (mid) * mid;
            long m2 = static_cast<long> (mid + 1) * (mid + 1); 
            if (m2 <= x) {
                start = mid + 1;
            } else if (m1 > x) {
                end = mid - 1;
            } else {
                return mid;
            }
        }
    }
};
