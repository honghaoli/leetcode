class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        pre_set();
        map['A'] = 0;
        map['C'] = 1;
        map['T'] = 2;
        map['G'] = 3;
        vector<string> result;
        unordered_set<int> dup;
        unordered_set<int> found;
        int hash = hashLen(s, 0);
        dup.insert(hash);
        for (int i = kLen; i < s.size(); i++) {
            hash = rollingHash(s, i, hash);
            if (dup.count(hash) > 0) {
                if (found.count(hash) == 0) {
                    result.push_back(s.substr(i - kLen + 1, kLen));
                    found.insert(hash);
                }
            } else {
                dup.insert(hash);
            }
        }
        return result;
    }

private:
    const int R = 4;
    const int kLen = 10;
    unordered_map<char, int> map;
    int R_SHIFT;

    void pre_set() {
        R_SHIFT = 1;
        for (int i = 0; i < kLen - 1; i++) {
            R_SHIFT = R_SHIFT * R;
        }
    }

    int hashLen(string &s, int start) {
        int value = 0;
        for (int i = start; i < start + kLen; i++) {
            value = value * R + map[s[i]];
        }
        return value;
    }

    int inline rollingHash(string &s, int i_add, int pre_hash) {
        return (pre_hash - map[s[i_add - kLen]] * R_SHIFT) * R + map[s[i_add]];
    }

};
