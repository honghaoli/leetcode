class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        dp.resize(n + 1);
        dp[1] = {"0", "1", "8"};
        return find(n, false);
    }

private:
    vector<vector<string>> dp;
    unordered_map<string, string> invert{{"1" , "1"}, {"8" , "8"}, {"6" , "9"}, {"9" , "6"}};
    
    vector<string> find(int n, bool leading_zero = true) {
        vector<string> result;
        if (n <= 0) return {""};
        if (dp[n].size() != 0) return dp[n];
        for (string &s : find(n - 2)) {
            if (leading_zero) {
                result.push_back("0" + s + "0");
            }
            for (auto &p : invert) {
                result.push_back(p.first + s + p.second);
            }
        }
        dp[n] = result;
        return result;
    }
};