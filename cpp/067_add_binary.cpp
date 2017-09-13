class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        string result = "";
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int tmp = carry;
            if (i >= 0)
                tmp += a[i] - '0';
            if (j >= 0)
                tmp += b[j] - '0';
            if (tmp > 1) {
                carry = 1;
                tmp -= 2;
            } else {
                carry = 0;
            }
            result += std::to_string(tmp);
            i--;
            j--;
        }

        if (carry != 0)
            result += "1";

        std::reverse(result.begin(), result.end());
        return result;
    }
};
