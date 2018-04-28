
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1)) return 1;
        int lo = 2, hi = n;
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            if (isBadVersion(mid - 1))
                hi = mid - 1;
            else if (!isBadVersion(mid))
                lo = mid + 1;
            else
                return mid;
        }
        return 0;
    }
};
