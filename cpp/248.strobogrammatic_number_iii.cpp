class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        if (compare(low, high) > 0) return 0;
        if (compare(low, high) == 0) return isStro(low) ? 1 : 0;
        int result = smallOrEqual(high) - smallOrEqual(low);
        if (isStro(low))
            ++result;
        return result;
    }

private:
    int smallOrEqual(string &num) {
        return sameLength(num) + lessDigits(num);
    }

    int sameLength(string &num) {
        vector<string> same_len = findStrobogrammatic(num.size());
        int result = 0;
        for (string &s : same_len) {
            if (compare(s, num) <= 0)
                ++result;
        }
        return result;
    }

    int lessDigits(string &num) {
        int n = num.size();
        int result = 0;
        for (int i = 1; i < n; ++i) {
            result += numForDigits(i);
        }
        return result;
    }

    // total number of this number for n digits.
    // 0, 1, 8, 6, 9
    // 0 cannot be the first one or the last one, if there are more than one digits
    // first: means how many choices can the first digit be
    int numForDigits(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 3;
        int result = 4;
        for (int i = 2; i <= n / 2; ++i) {
            result *= 5;
        }
        // if odd digits, the mid can be 0, 1, 8
        if (n % 2 != 0)
            result *= 3;
        // cout << n << " digits: " << result << endl;
        return result;
    }

    unordered_map<char, char> invert2{{'0' , '0'}, {'1' , '1'}, {'8' , '8'}, {'6' , '9'}, {'9' , '6'}};
   
    bool isStro(string &num) {
        int n = num.size();
        for (int i = 0; i < n - 1 - i; ++i) {
            if (num[i] != invert2[num[n - i - 1]]) return false;
        }
        if (n % 2 == 1) {
            char &c = num[(n - 1) / 2];
            if (c != '0' && c != '1' && c != '8') return false;
        }
        return true;
    }

    int compare(string &num1, string &num2) {
        if (num1.size() < num2.size()) return -1;
        if (num1.size() > num2.size()) return 1;
        for (int i = 0; i < num1.size(); ++i) {
            if (num1[i] < num2[i]) return -1;
            if (num1[i] > num2[i]) return 1;
        }
        return 0;
    }

    vector<string> findStrobogrammatic(int n) {
        dp.resize(n + 1);
        dp[1] = {"0", "1", "8"};
        return find(n, false);
    }

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