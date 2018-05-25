static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        const int N = 26;
        // frequency of all char
        vector<int> freq(N, 0);
        int min_len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 0) {
                min_len = i + 1;        // last time to see a new char, so the length should >= this char.
            }
            freq[s[i] - 'a']++;
        }
        // try possible length
        for (int len = min_len; len <= s.size() / 2; len++) {
            if (check_possible(s.size(), len, freq) && validate(s, len))
                return true;
        }
        return false;
    }

private:
    bool check_possible(int n, int len, vector<int> &freq) {
        if (n % len != 0) return false;
        int num = n / len;       // number of repeated substrings
        for (int f : freq) {
            if (f % num != 0)    // all number of char should be k * num
                return false;
        }
        return true;
    }

    bool validate(string &s, int len) {
        int num = s.size() / len;
        for (int i = 0; i < len; i++) {
            for (int k = 1; k < num; k++) {
                if (s[k * len + i] != s[i])
                    return false;
            }
        }
        return true;
    }
};
