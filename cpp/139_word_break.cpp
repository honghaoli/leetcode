class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // memorize if string[start, end] could be construct using words in dict.
        // -1 means not calculated.
        vector<int> canBreak(s.size() + 1, -1);
        canBreak[s.size()] = 1;
        
        // convert list of words into hashmap for O(1) time look-up.
        unordered_map<string, bool> dict;
        for (string &s : wordDict) {
            dict[s] = true;
        }
        
        return subWordBreak(s, 0, s.size(), dict, canBreak);
    }
    
    
    bool subWordBreak(string &s, int start, int end, unordered_map<string, bool> &dict, vector<int> &mem) {
        // 1 means substring can be construct, 0 means not, -1 means not calculated.
        if (mem[start] == 1)
            return true;
        else if (mem[start] == 0)
            return false;
            
        // -1, not calculated, then calculate
        for (int i = start + 1; i <= end; i++) {
            bool head = dict.count(s.substr(start, i - start)) > 0;
            if (head && subWordBreak(s, i, end, dict, mem)) {
                mem[start] = 1;
                return true;
            }
        }
        
        // still not found, can not be constructed.
        mem[start] = 0;
        return false;
    }
};
