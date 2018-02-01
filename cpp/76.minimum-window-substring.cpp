// class Solution {
// public:
    // string minWindow(string s, string t) {
        // if (t.size() > s.size()) return "";

        // // build target char hashmap
        // unordered_map<char, int> target;
        // for (int k = 0; k < t.size(); k++) {
            // if (target.count(t[k]) > 0)
                // target[t[k]]++;
            // else
                // target[t[k]] = 1;
        // }

        // // start to find
        // int i = 0, j = 0;
        // int d = s.size() + 1;
        // string result = "";

        // for (j = 0; j < s.size(); j++) {
            // char &c = s[j];
            // if (target.count(c) > 0) {
                // target[c]--;
                // // try to move i, if the s[i] == s[j]
                // if (target[c] <= 0) {
                    // while (i <= j) {
                        // char &ci = s[i];
                        // if (target.count(ci) == 0) {
                            // i++;
                        // } else if (target[ci] < 0) {
                            // target[ci]++;
                            // i++;
                        // } else {
                            // break;
                        // }
                    // }
                // }
                // // if found all chars
                // if (target[c] <= 0 && foundAllChars(target) && j - i + 1 < d) {
                    // d = j - i + 1;
                    // result = s.substr(i, j - i + 1);
                // }
            // }
        // }

        // return result;
    // }


// private:
    // bool hasFoundAllChars = false;
    // bool foundAllChars(unordered_map<char, int> &target) {
        // if (hasFoundAllChars) return true;
        // for (auto it = target.cbegin(); it != target.cend(); ++it) {
            // if (it->second > 0)
                // return false;
        // }
        // return true;
    // }
// };




// more concise
// vector version rather than hashmap
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        // build target char vector
        vector<int> target(128, 0);
        for (auto &c : t)
            target[c]++;

        // start to find
        int start = 0, end = 0;
        int counter = t.size();
        int head = 0;
        int d = s.size() + 1;

        // move the end pointer
        for (end = 0; end < s.size(); end++) {
            if (target[s[end]] > 0)
                counter--;
            target[s[end]]--;
            // move the start pointer
            while (counter == 0) {
                if (end - start + 1 < d) {
                    d = end - start + 1;
                    head = start;
                }
                if (target[s[start]] == 0)
                    counter++;
                target[s[start]]++;
                start++;
            }
        }

        if (d > s.size())
            return "";
        else
            return s.substr(head, d);
    }

};
