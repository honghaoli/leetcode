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











// BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<int>> neigh = build_neigh(wordList);
        vector<bool> visited(wordList.size(), false);
        vector<int> steps(wordList.size(), 0);
        queue<int> start;
        int end = -1;
        for (int i = 0; i < wordList.size(); i++) {
            if (diff_one(wordList[i], beginWord)) {
                start.push(i);
                visited[i] = true;
                steps[i] = 1;
            } 
            if (wordList[i] == endWord) {
                end = i;
            }
        }
        if (end == -1 || start.empty()) return 0;
        
        while (!start.empty()) {
            int current = start.front();
            if (current == end) return steps[current] + 1;
            start.pop();
            for (auto &i : neigh[current]) {
                if (!visited[i]) {
                    start.push(i);
                    visited[i] = true;
                    steps[i] = steps[current] + 1;
                }
            }
        }
        return 0;
    }
    

private:
    vector<vector<int>> build_neigh(vector<string> &wordList) {
        vector<vector<int>> neigh(wordList.size(), vector<int>());
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (diff_one(wordList[i], wordList[j])) {
                    neigh[i].push_back(j);
                    neigh[j].push_back(i);
                }
            }
        }
        return neigh;
    }
    

    bool diff_one(string &w1, string &w2) {
        int d = 0;
        for (int i = 0; i < w1.size(); i++) {
            if (w1[i] != w2[i]) {
                d++;  
                if (d > 1) return false;
            } 
        }
        return d == 1;
    }
};



// this would very much improve the algorithm!
// 1. use hash set to store all key, and change each char with 26 possibles to avoid large comparison.
// 2. use two-end BFS.
class Solution {
public:
    // space O(n), total n strings, use set to store them.
    // time O(n * m * 26), n strings, m char per string, each char try 26 possible cases.
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for (auto &s : wordList) {
            dict.insert(s);
        }
        if (dict.count(endWord) == 0) return 0;     // endWord not in the wordList
        dict.erase(endWord);
        
        unordered_set<string> set1({beginWord});
        unordered_set<string> set2({endWord});
        unordered_set<string> tmp;
        int step = 0;
       
        while (!set1.empty()) {
            step++;
            tmp.clear();
            // for each string in the set
            for (auto s : set1) {
                // try to change each char in the string
                for (auto &c : s) {
                    const char origin = c;
                    for (int i = 0; i < 26; i++) {
                        c = 'a' + i;
                        // if this new string is in the other side set, found!
                        if (set2.count(s) > 0) {
                            return step + 1;
                        } else if (dict.count(s) > 0) {
                            // else, check if the new string is in dictionary
                            dict.erase(s);
                            tmp.insert(s);
                        }
                    }
                    // important, reset the string to original.
                    c = origin;
                }
            }
            // find the smaller size set, to be set1, thus is faster.
            set1 = (tmp.size() < set2.size() ? tmp : set2);
            set2 = (tmp.size() < set2.size() ? set2 : tmp);
        }
        return 0;
    }
    
};