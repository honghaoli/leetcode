class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if (n <= 1) return n;
        int result = 0;
        for (int mid = 0; mid < n; mid++) {
            // odd length
            for (int i = 0; mid - i >= 0 && mid + i < n && s[mid - i] == s[mid + i]; i++) {
                result++;
            }
            // even length
            for (int i = 0; mid - i >= 0 && mid + i + 1 < n && s[mid - i] == s[mid + i + 1]; i++) {
                result++;
            }
        }
        return result;
    }
};
