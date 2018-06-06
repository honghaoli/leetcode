class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result;
        for (auto &s : strs) {
            result += to_string(s.size());
            result += " ";
            result += s;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int len = next_length(s, i);
            result.push_back(s.substr(i, len));
            i += len;
        }
        return result;
    }

private:
    int next_length(string &s, int &i) {
        string num;
        while (s[i] != ' ') {
            num += s[i];
            ++i;
        }
        ++i;
        return stoi(num);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));