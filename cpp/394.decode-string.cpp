class Solution {
public:
    string decodeString(string s) {
        return decode(s, 0, s.size() - 1);
    }

private:
    string decode(string &s, int i, int j) {
        string result;
        if (j < i) return result;
        while (i <= j) {
            while (!isDigit(s[i]) && i <= j) {
                result += s[i++];
            }
            if (i > j) break;
            int len = next_num(s, i);
            int end = find_end(s, i);   // substring is [i, end]
            string sub = decode(s, i + 1, end - 1);     // neglect [, ] char
            for (int k = 0; k < len; ++k) {
                result += sub;
            }
            i = end + 1;
        }
        return result;
    }

    bool inline isDigit(char c) {
        if (c >= '0' && c <= '9') return true;
        return false;
    }

    int next_num(string &s, int &i) {
        string num;
        while (isDigit(s[i])) {
            num += s[i++];
        }
        return stoi(num);
    }

    int find_end(string &s, int i) {
        // should start with s[i] == '['
        if (s[i] != '[') throw;
        int left = 1;
        while (left > 0) {
            ++i;
            if (s[i] == '[') ++left;
            else if (s[i] == ']') --left;
        }
        return i;
    }
};
