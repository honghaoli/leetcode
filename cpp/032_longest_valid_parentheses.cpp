class Solution {
public:
    // solution 1.0
    // valid parenthese always has left >= right at any given point.
    // in case of the string ends with left > right, not reach the point to record the length, do a reverse from right to left
    int longestValidParentheses(string s) {
        // forward, from left to right;
        int len1 = longestOneDirection(s, '(', ')');
        reverse(s.begin(), s.end());
        // backward, from left to right
        int len2 = longestOneDirection(s, ')', '(');
        return max(len1, len2);
    }
    
    int longestOneDirection(string &s, char l, char r) {
        int max_len = 0;
        int length = 0;
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == l) {
                left++;
            } else if (s[i] == r) {
                right++;
            }
            
            if (right > left) {
                length = 0;
                right = 0;
                left = 0;
            } else {
                length++;
                if (right == left) {
                    if (length > max_len) {
                        max_len = length;
                    }
                }
            }
        }
        
        return max_len;        
    }
};
