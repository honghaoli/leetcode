class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() < 2) return true;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isValid(s[i])) {
                i++;
            } else if (!isValid(s[j])) {
                j--;
            } else {
                if (lowerCase(s[i]) != lowerCase(s[j]))
                    return false;
                else {
                    i++;
                    j--;
                }
            }
        }
        
        return true;
    }
    
private:
    bool inline isValid(char &c) {
        return (c >= 'A' && c <= 'Z')  || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
    
    char inline lowerCase(char &c) {
        if (c >= 'A' && c <= 'Z')
            return c - 'A' + 'a';
        else
            return c;
    }
};