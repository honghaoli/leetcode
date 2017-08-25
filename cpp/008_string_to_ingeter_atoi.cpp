class Solution {
public:
    int myAtoi(string str) {
        int size = str.size();
        bool minus = false;
        int i = 0;
        long num = 0;
        
        // skip white space, find the sign
        while (i < size) {
            if (str[i] == '+') {
                minus = false;
                i++;
                break;
            }
            else if (str[i] == '-') {
                minus = true;
                i++;
                break;
            }
            else if (str[i] != ' ')
                break;
            i++;
        }
        
        // find the digits
        while (i < size) {
            if (charIsDigit(str[i])) {
                int d = charToDigit(str[i]);
                if (minus) {
                    num = num * 10 - d;
                    if (num < std::numeric_limits<int>::min())
                        return std::numeric_limits<int>::min();
                } else {
                    num = num * 10 + d;
                    if (num > std::numeric_limits<int>::max())
                        return std::numeric_limits<int>::max();
                }
                i++;
            } else {
                break;
            }
        }
        
              
        return num;
    }
    
    bool charIsDigit(char c) {
        if (c >= 48 && c <= 57)
            return true;
        else 
            return false;
    }
    
    int charToDigit(char c) {
        return c - 48;
    }
};
