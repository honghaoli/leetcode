// class Solution {
// public:
    // vector<int> findSubstring(string s, vector<string>& words) {
        // if (words.size() < 1) return {};
        // int len = words[0].size();
        // int min_len = words.size() * len;
        // if (min_len > s.size()) return {};

        // unordered_map<string, int> hash = generateHash(words);

        // vector<int> result;
        // for (int start = 0; start <= s.size() - min_len; start++) {
            // unordered_map<string, int> tmp = hash;
            // int counter = words.size();
            // for (int i = start; i <= s.size() - len; i += len) {
                // string str = s.substr(i, len);
                // if (tmp.count(str) == 0 || tmp[str] == 0) break;    // not match
                // tmp[str]--;
                // counter--;
                // // found all words
                // if (counter == 0) {
                    // result.push_back(start);
                    // break;
                // }
            // }
        // }

        // return result;
    // }


// private:
    // unordered_map<string, int> generateHash(vector<string> &words) {
        // unordered_map<string, int> hash;
        // // CANNOT ASSUME NO DUPLICATES!!!
        // for (auto &s : words) {
            // if (hash.count(s) > 0)
                // hash[s]++;
            // else
                // hash[s] = 1;
        // }
        // return hash;
    // }

// };
//




// inspired by the discussion
//
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.size() < 1) return {};
        int len = words[0].size();
        int min_len = words.size() * len;
        if (min_len > s.size()) return {};

        unordered_map<string, int> hash = generateHash(words);

        vector<int> result;
        for (int shift = 0; shift < len; shift++) {
            unordered_map<string, int> tmp = hash;
            int left = shift;
            int counter = words.size();
            for (int end = shift; end <= s.size() - len; end += len) {
                string str = s.substr(end, len);
                if (tmp[str] > 0)
                    counter--;
                tmp[str]--;
                while (counter == 0) {
                    if (end - left == (words.size() - 1) * len)
                        result.push_back(left);
                    string str_left = s.substr(left, len);
                    if (tmp[str_left] == 0)
                        counter++;
                    tmp[str_left]++;
                    left += len;
                }
            }
        }

        return result;
    }


private:
    unordered_map<string, int> generateHash(vector<string> &words) {
        unordered_map<string, int> hash;
        // CANNOT ASSUME NO DUPLICATES!!!
        for (auto &s : words) {
            if (hash.count(s) > 0)
                hash[s]++;
            else
                hash[s] = 1;
        }
        return hash;
    }

};





// more concise and clear solution
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.size() == 0 || words.size() == 0 || words[0].size() == 0) return result;

        int nw = words.size();
        int wl = words[0].size();
        int ns = s.size();
        unordered_map<string, int> counts;
        for (auto &s : words) {
            if (counts.count(s) > 0) {
                counts[s]++;
            } else {
                counts[s] = 1;
            }
        }
        
        for (int shift = 0; shift < wl; shift++) {
            unordered_map<string, int> hash;
            int count = 0;
            int start = shift;
            string right, left;
            for (int end = shift; end <= ns - wl; end += wl) {
                right = s.substr(end, wl);
                if (counts.count(right) == 0) continue;
                hash[right]++;
                count++;
                // remove duplicates
                while (hash[right] > counts[right] && start < end) {
                    left = s.substr(start, wl);
                    if (counts.count(left) > 0) {
                        hash[left]--;
                        count--;
                    }
                    start += wl;
                }
                // remove pre- non words
                while(counts.count(s.substr(start, wl)) == 0 && start < end) {
                    start += wl;
                }
                // check if it is valid pos
                if (count == nw && end - start == (nw - 1) * wl) {
                    result.push_back(start);
                }
            }
        }
        
        return result;
    }
};