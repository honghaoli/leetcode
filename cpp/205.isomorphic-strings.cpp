class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> map(256, -1);
        vector<int> map2(256, -1);
        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]] < 0 && map2[t[i]] < 0) {
                map[s[i]] = t[i];
                map2[t[i]] = s[i];
            }
            else if (map[s[i]] != t[i])
                return false;
        }
        return true;
    }
};
