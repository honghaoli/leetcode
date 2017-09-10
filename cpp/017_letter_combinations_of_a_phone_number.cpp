class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        vector<string> result = {""};
        unordered_map<char, string> map = { {'2' , "abc"},
                                           {'3' , "def"},
                                           {'4' , "ghi"},
                                           {'5' , "jkl"},
                                           {'6' , "mno"},
                                           {'7' , "pqrs"},
                                           {'8' , "tuv"},
                                           {'9' , "wxyz"},
                                           {'0' , " "}
                                          };
        addLettersFromDigits(result, digits, 0, map);
        return result;
    }

    void addLettersFromDigits(vector<string> &letters, string &digits, int start, unordered_map<char, string> &map) {
        int len = letters.size();
        for (int k = 0; k < len; k++) {
            if (map.count(digits[start]) > 0) {
                string &str = letters[k];
                string tmp = str;
                string &lett = map[digits[start]];
                str += lett[0];
                for (int i = 1; i < lett.size(); i++) {
                    letters.push_back(tmp + lett[i]);
                }
            }
        }
        if (start < digits.size() - 1)
            addLettersFromDigits(letters, digits, start + 1, map);
    }
};
