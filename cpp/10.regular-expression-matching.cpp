// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         vector<vector<int>> dp = vector<vector<int>>(p.size() + 1, vector<int>(s.size() + 1, -1));
//         return isMatch(s, p, 0, 0, dp);
//     }


// private:
//     bool isMatch(string &s, string &p, int pi, int si, vector<vector<int>> &dp) {
//         // found all
//         if (pi == p.size() && si == s.size()) return true;
//         // pattern found end, the string not, so cannot match.
//         if (pi == p.size()) return false;

//         // check dynamic programm memory
//         if (dp[pi][si] == 0) return false;
//         if (dp[pi][si] == 1) return true;

//         // not visited before, calculate it.
//         // if current char has wildcard number
//         if (pi < p.size() - 1 && p[pi + 1] == '*') {
//             // consider * = 0 char
//             if (isMatch(s, p, pi + 2, si, dp)) {
//                 dp[pi][si] = 1;
//                 return true;
//             }
//             // * > 0
//             for(; si < s.size() && matchChar(p[pi], s[si]); si++) {
//                 if (isMatch(s, p, pi + 2, si + 1, dp)) {
//                     dp[pi][si] = 1;
//                     return true;
//                 }
//             }
//             // not found match
//             dp[pi][si] = 0;
//             return false;
//         } else {
//             if (si == s.size()) return false;
//             // only one char to compare
//             if (matchChar(p[pi], s[si]))
//                 return isMatch(s, p, pi + 1, si + 1, dp);
//             else {
//                 dp[pi][si] = 0;
//                 return false;
//             }
//         }
//     }

//     bool inline matchChar(char &cp, char &cs) {
//         if (cp == '.')
//             return true;
//         return cp == cs;
//     }
// };



// DP from bottom to up
// inspired by discussion
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1, false));      
        dp[0][0] = true;

        for (int pi = 1; pi <= p.size(); pi++) {
            // initial for s = "" empty
            if (p[pi - 1] == '*') {
                dp[pi][0] = dp[pi - 2][0];
            }
            for (int si = 1; si <= s.size(); si++) {
                if (match(p[pi - 1], s[si - 1])) {
                    dp[pi][si] = dp[pi - 1][si - 1];
                } else if (p[pi - 1] == '*') {
                    dp[pi][si] = dp[pi - 2][si] || (match(p[pi - 2], s[si - 1]) && dp[pi][si - 1]);
                }
            }
        }

        return dp[p.size()][s.size()];
    }

private:
    bool inline match(char &p, char &c) {
        if (p == '.') return true;
        return p == c;
    }
};