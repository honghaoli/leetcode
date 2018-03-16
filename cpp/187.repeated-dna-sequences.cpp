class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        pre_set(kLen);
        int hash = hashLen(s, 0, kLen);
        unordered_map<int, vector<int>> idx;
        unordered_set<int> dup;
        idx[hash] = {0};
        for (int i = kLen; i < s.size(); i++) {
            hash = rollingHash(s, kLen, i, hash);
            int i_start = i - kLen + 1;
            if (idx.count(hash) > 0) {
                bool found = false;
                for (auto &index : idx[hash]) {
                    if (compare(s, index, i_start, kLen)) {
                        found = true;
                        if (dup.count(index) == 0) {
                            dup.insert(index);
                        }
                    }
                }
                // hash collision, different strings has the same hash value
                if (!found)
                    idx[hash].push_back(i_start);
            } else {
                idx[hash] = {i_start};
            }
        }
        return toStrings(dup, s);
    }

private:
    const int R = 26;
    const int P = 1301081;
    const int kLen = 10;
    int R_SHIFT;

    void pre_set(int len) {
        R_SHIFT = 1;
        for (int i = 0; i < len - 1; i++) {
            R_SHIFT = (R_SHIFT * R) % P;
        }
    }

    int hashLen(string &s, int start, int len) {
        int value = 0;
        for (int i = start; i < start + len; i++) {
            value = (value * R + s[i]) % P;
        }
        return value;
    }

    int rollingHash(string &s, int len, int i_add, int pre_hash) {
        int i_remove = i_add - len;
        int value = (pre_hash - s[i_remove] * R_SHIFT % P + P) % P;
        value = (value * R + s[i_add]) % P;
        return value;
    }

    bool compare(string &s, int i1, int i2, int len) {
        for (int i = 0; i < len; i++) {
            if (s[i1 + i] != s[i2 + i]) return false;
        }
        return true;
    }

    vector<string> toStrings(unordered_set<int> &dup, string &s) {
        vector<string> result;
        for (auto iter = dup.begin(); iter != dup.end(); ++iter) {
            result.push_back(s.substr(*iter, kLen));
        }
        return result;
    }
};
