class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1; 
        int count = 0;
        for (; i < j; i++, j--) {
            if (s[i] != s[j]) {
                if (count < 1) {
                    count++;
                    return valid(s, i+1, j) || valid(s, i, j-1);
                } else {
                    return false;
                }
            } 
        }
        return true;
    }
    

private:
    bool valid(string &s, int i, int j) {
        if (i >= j) return true;
        for (; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};





// from discussion
// more concise recursive version
// can be extended to arbitrary number of count
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1; 
        return valid(s, 0, j, 1);
    }
    

private:
    bool valid(string &s, int i, int j, int count) {
        if (i >= j) return true;
        if (s[i] == s[j]) {
            return valid(s, i + 1, j - 1, count);
        } else if (count > 0) {
            return valid(s, i + 1, j, count - 1) || valid(s, i, j - 1, count - 1);
        } else {
            return false;
        }
    }
};