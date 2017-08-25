class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() < 1)
            return "";
        
        int min_len = std::numeric_limits<int>::max();
        string shortest = strs.at(0);
        for (string &s : strs) {
            if (s.size() < min_len) {
                min_len = s.size();
                shortest = s;
            }
        }
        
        string result = "";
        char c;
        bool finished = false;
        for(int i = 0; i < min_len; i++) {
            c = shortest[i];
            for (string &s : strs) {
                if (s[i] != c) {
                    finished = true;
                    break;
                }
            }
            if (finished) {
                break;
            } else {
                result += c;
            }
        }
        
        return result;
    }
};
