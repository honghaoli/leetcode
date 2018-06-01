class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        int n = s.size();
        if (n <= 1) return result;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                string tmp = s;
                tmp[i] = '-';
                tmp[i + 1] = '-';
                result.push_back(tmp);
            }
        }
        return result;
    }
};