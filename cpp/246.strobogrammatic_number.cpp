class Solution {
public:
    bool isStrobogrammatic(string num) {
        if (num.size() == 0) return true;
        for (int i = 0; i <= num.size() / 2; ++i) {
            if (!canRotate(num[i])) return false;
            if (rotate(num[i]) != num[num.size() - 1 - i]) return false;
        }
        return true;
    }

private:
    bool inline canRotate(char c) {
        if (c == '3' || c == '4' || c == '7' || c == '2' || c == '5') return false;
        return true;
    }

    char rotate(char c) {
        if (c == '0' || c == '1' || c == '8') {
            return c;
        } else if (c == '6') {
            return '9';
        } else if (c == '9') {
            return '6';
        }
        //
        throw;
    }
};