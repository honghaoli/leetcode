// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         vector<vector<int>> dp(p.size() + 1, vector<int>(s.size() + 1, -1));
//         return isMatch(s, p, 0, 0, dp);
//     }

// private:
//     bool isMatch(string &s, string &p, int pi, int si, vector<vector<int>> &dp) {
//         // both reach the end, they match
//         if (pi >= p.size() && si >= s.size()) return true;
//         // only pattern reaches the end, not match
//         if (pi >= p.size()) return false;
//         // only string reaches the end, p not *, not match
//         if (si >= s.size() && p[pi] != '*') return false;

//         // check dp memory
//         if (dp[pi][si] == 0) return false;
//         if (dp[pi][si] == 1) return true;

//         if (p[pi] == '?' || p[pi] == s[si]) {
//             if(isMatch(s, p, pi + 1, si + 1, dp)) {
//                 dp[pi][si] = 1;
//                 return true;
//             } else {
//                 dp[pi][si] = 0;
//                 return false;
//             }
//         } else if (p[pi] == '*') {
//             if(isMatch(s, p, pi + 1, si, dp) || (si < s.size() && isMatch(s, p, pi, si + 1, dp) ) ) {
//                 dp[pi][si] = 1;
//                 return true;
//             } else {
//                 dp[pi][si] = 0;
//                 return false;
//             }
//         } else {
//             dp[pi][si] = 0;
//             return false;
//         }
//     }
// };



// dp solution from bottom to up
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int ns = s.size();
//         int np = p.size();
//         // dp[ip][is] means match for p[0:ip) and s[0:is), not inclusive.
//         vector<vector<bool>> dp(np + 1, vector<bool>(ns + 1, false));
//         dp[0][0] = true;

//         for (int ip = 1; ip <= np; ip++) {
//             dp[ip][0] = (p[ip - 1] == '*') && dp[ip - 1][0];
//             for (int is = 1; is <= ns; is++) {
//                 if (p[ip - 1] == '?' || p[ip - 1] == s[is - 1]) {
//                     dp[ip][is] = dp[ip - 1][is - 1];
//                 } else if (p[ip - 1] == '*') {
//                     dp[ip][is] = dp[ip][is - 1] || dp[ip - 1][is];
//                 }
//             }
//         }

//         return dp[np][ns];
//     }
// };



// O(p*s) algorithm
// inspired by discussion
class Solution {
public:
    bool isMatch(string s, string p) {
        bool star = false;
        int marker_p, marker_s;
        int pi = 0, si = 0;
        while (si < s.size()) {
            if (pi < p.size() && (p[pi] == '?' || p[pi] == s[si])) {
                pi++;
                si++;
            } else if (pi < p.size() && p[pi] == '*') {
                star = true;
                // find the end of this * sequence.
                while (pi < p.size() && p[pi] == '*')
                    pi++;
                marker_p = pi - 1;
                marker_s = si;
            } else {
                // p[pi] != s[si]
                if (!star) return false;    // no star, not match
                marker_s++;     // try again, from next marker_s char.
                si = marker_s;
                pi = marker_p + 1;
            }
        }
        // in case trailing * in p
        while (pi < p.size() && p[pi] == '*') {
            pi++;
        }

        return pi == p.size();
    }
};