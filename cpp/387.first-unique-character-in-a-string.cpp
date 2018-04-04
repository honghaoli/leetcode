class Solution {
public:
    int firstUniqChar(string s) {
        const int N = 26;
        vector<int> hash(N, 0);
        for (auto &c : s) 
            hash[c - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
