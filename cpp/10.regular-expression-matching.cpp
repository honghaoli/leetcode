class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp = vector<vector<int>>(p.size() + 1, vector<int>(s.size() + 1, -1));
        return isMatch(s, p, 0, 0, dp);
    }


private:
    bool isMatch(string &s, string &p, int pi, int si, vector<vector<int>> &dp) {
        // found all
        if (pi == p.size() && si == s.size()) return true;
        // pattern found end, the string not, so cannot match.
        if (pi == p.size()) return false;

        // check dynamic programm memory
        if (dp[pi][si] == 0) return false;
        if (dp[pi][si] == 1) return true;

        // not visited before, calculate it.
        // if current char has wildcard number
        if (pi < p.size() - 1 && p[pi + 1] == '*') {
            // consider * = 0 char
            if (isMatch(s, p, pi + 2, si, dp)) {
                dp[pi][si] = 1;
                return true;
            }
            // * > 0
            for(; si < s.size() && matchChar(p[pi], s[si]); si++) {
                if (isMatch(s, p, pi + 2, si + 1, dp)) {
                    dp[pi][si] = 1;
                    return true;
                }
            }
            // not found match
            dp[pi][si] = 0;
            return false;
        } else {
            if (si == s.size()) return false;
            // only one char to compare
            if (matchChar(p[pi], s[si]))
                return isMatch(s, p, pi + 1, si + 1, dp);
            else {
                dp[pi][si] = 0;
                return false;
            }
        }
    }

    bool inline matchChar(char &cp, char &cs) {
        if (cp == '.')
            return true;
        return cp == cs;
    }
};
