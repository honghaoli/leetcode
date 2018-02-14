class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        
        bool canReach = false;
        vector<int> begin(n, -1);
        for (int i = 0; i < n; i++) {
            if (diff_one(beginWord, wordList[i])) {
                canReach = true;
                begin[i] = 1;
            }
        }
        if (!canReach) return false;
        
        canReach = false;
        vector<int> end(n, -1);
        for (int i = 0; i < n; i++) {
            if (endWord == wordList[i]) {
                canReach = true;
                end[i] = 0;
            }
        }
        if (!canReach) return false;
        
        for (int step = 1; step <= n; step++) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (begin[i] == step) {
                    found = true;
                    if (end[i] == 0) return begin[i] + end[i] + 1;
                    for (int j = 0; j < n; j++) {
                        if (begin[j] < 0 && diff_one(wordList[i], wordList[j])) 
                            begin[j] = step + 1;
                    }
                }
            }
            if (!found) return false;
        }
    }
    

private:
    bool diff_one(string &w1, string &w2) {
        int d = 0;
        for (int i = 0; i < w1.size(); i++) {
            if (w1[i] != w2[i])  {
                d++;
                if (d > 1) return false;
            }
        }
        return d == 1;
    }
};