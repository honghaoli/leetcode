class Solution {
public:
    int firstUniqChar(string s) {
        const int N = 26;
        vector<vector<int>> hash(N, vector<int>{0, -1});
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'][0]++;
            hash[s[i] - 'a'][1] = i;
        }
        int idx = s.size();
        for (int i = 0; i < N; i++) {
            if (hash[i][0] == 1)
                idx = min(idx, hash[i][1]);
        }
        if (idx == s.size())
            return -1;
        return idx;
    }
};

