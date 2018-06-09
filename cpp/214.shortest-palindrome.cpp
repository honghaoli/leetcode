class Solution {
public:
    string shortestPalindrome(string s) {
        int end = s.size() - 1;
        for ( ; end > 0; --end) {
            if (valid(s, end)) break;
        }
        string tmp = s.substr(end + 1, s.size() - end - 1);
        reverse(tmp.begin(), tmp.end());
        return tmp + s;
    }

private:
    bool valid(string &s, int end) {
        if (end == 0) return true;
        for (int i = 0; i <= end / 2; ++i) {
            if (s[i] != s[end - i]) return false;
        }
        return true;
    }
};
