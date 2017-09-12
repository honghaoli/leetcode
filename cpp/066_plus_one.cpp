class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.size() < 1)
            return digits;

        int carry = 0;
        digits[digits.size() - 1]++;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int tmp = digits[i] + carry;
            if (tmp > 9) {
                tmp -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            digits[i] = tmp;
        }

        if (carry != 0) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};
