class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int result = smallOrEqual(high, 0) - smallOrEqual(low, 0);
        if (isStro(low))
            ++result;
        return result;
    }

private:
    int sameLength(string &num) {
        int n = num.size();
        if (start >= n / 2) return 0;
        if (num[0] == '0')
            throw;
        else if (num[0] == '1')
            if (num[n - 1] >= '1') 
                return equalMid(num, start + 1, n - 2);
            else
                return smallerMid(num, start + 1, n - 2);
    }

    int smallerMid(string &num, int start, int end) {
        if (start > end) return 0;
    }

    int equalMid(string &num, int start, int end) {
        if (start > end) return 1;
    }

    int lessDigits(string &num) {
        int n = num.size();
        int result = 0;
        for (int i = 1; i < n; ++i) {
            result += numForDigits(i);
        }
        return result;
    }

    // total number of this number for n digits.
    // 0, 1, 8, 6, 9
    // 0 cannot be the first one or the last one, if there are more than one digits
    // first: means how many choices can the first digit be
    int numForDigits(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 3;
        int result = 4;
        for (int i = 2; i <= n / 2; ++i) {
            result *= 5;
        }
        // if odd digits, the mid can be 0, 1, 8
        if (n % 2 != 0)
            result *= 3;
        cout << n << " digits: " << result << endl;
        return result;
    }

    int numForDigitsIncludingZero(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 3;
        int result = 5;
        for (int i = 1; i <= n / 2; ++i) {
            result *= 5;
        }
        // if odd digits, the mid can be 0, 1, 8
        if (n % 2 != 0)
            result *= 3;
        return result;
    }

    bool isStro(string num) {
        unordered_set<int> all {'0', '1', '6', '8', '9'};
        for (char c : num) {
            if (all.count(c) == 0) return false;
        }
        return true;
    }
};