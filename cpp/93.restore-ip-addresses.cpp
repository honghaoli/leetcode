class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        if (n > 12 || n < 4) return {};
        vector<string> result;
        // try all place for 3 dots
        for (int p3 = 3; p3 < n; p3++) {
            if (!isValid(s, p3, n - p3)) continue;
            for (int p2 = max(p3 - 3, 2); p2 < min(p3, 7); p2++) {
                if (!isValid(s, p2, p3 - p2)) continue;
                for (int p1 = max(p2 - 3, 1); p1 < min(p2, 4); p1++) {
                    if (!isValid(s, p1, p2 - p1)) continue;
                    if (!isValid(s, 0, p1)) continue;
                    string tmp = s;
                    tmp.insert(p3, 1, '.');
                    tmp.insert(p2, 1, '.');
                    tmp.insert(p1, 1, '.');
                    result.push_back(tmp);
                }
            }
        }
        
        return result;
    }
    

private:
    bool inline isValid(string &s, int i, int len) {
        string tmp = s.substr(i, len);
        int num = stoi(tmp);
        if (num > 255) return false;
        if (len > 1 && tmp[0] == '0') return false;
        return true;
    }
};