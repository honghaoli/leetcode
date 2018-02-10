class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> one;
        dfs(s, 0, one, result);
        return result;
    }
    

private:
    // try substring start from s[start]
    void dfs(string &s, int start, vector<string> &one, vector<vector<string>> &result) {
        if (start == s.size()) {
            result.push_back(one);
            //one.clear();      // This line cause leetcode server RUNTIME ERROR!!!
            return;
        }
        
        // the cut position is after s[cut - 1]
        for (int cut = start + 1; cut <= s.size(); cut++) {
            if (isPalindrome(s, start, cut - 1)) {
                one.push_back(s.substr(start, cut - start));
                dfs(s, cut, one, result);
                one.pop_back();
            }
        }
    }
    
    
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] == s[end]) {
                start++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }
};





