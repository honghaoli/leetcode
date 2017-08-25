class Solution {
public:
    string intToRoman(int num) {
        vector<int> digits {num % 10,  (num / 10) % 10,  (num / 100) % 10, num / 1000};
        vector<vector<string>> chars {
            {"" , "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}
        };
        string result = "";
        for (int i = 4; i > 0; i--) {
            result += chars[i-1][digits[i-1]];
        }
        return result;
    }
};
