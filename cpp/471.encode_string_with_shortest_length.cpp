class Solution {
public:
    string encode(string s) {
        dp = vector<vector<string>>(s.size(), vector<string>(s.size(), ""));
        return encode(s, 0, s.size() - 1);
    }

private:
    vector<vector<string>> dp;

    string encode(string &s, int i, int j) {
        if (dp[i][j] != "") return dp[i][j];
        int len = j - i + 1;
        if (len <= 4) return s.substr(i, len);      // less than 4 length, no need to compress
        // check if this substring is repeated strings
        string sub = s.substr(i, len);
        int k = (sub + sub).find(sub, 1);
        // it is repeated string
        if (k < len) {
            dp[i][j] = to_string(len / k) + "[" + encode(s, i, i + k - 1) + "]";
            return dp[i][j];
        }
        // else, try to separate this substring into two part
        for (int k = i; k < j; ++k) {
            string tmp = encode(s, i, k) + encode(s, k + 1, j);
            if (tmp.size() < sub.size())
                sub = tmp;
        }
        dp[i][j] = sub;
        return sub;
    }
};