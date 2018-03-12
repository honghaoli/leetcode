class WordDistance {
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); i++) {
            pos[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        if (word2 < word1)
            swap(word1, word2);
        if (dict.count(word1) > 0 && dict[word1].count(word2) > 0)
            return dict[word1][word2];
        dict[word1][word2] = calculate(word1, word2); 
        return dict[word1][word2];
    }

private:
    unordered_map<string, unordered_map<string, int>> dict;
    unordered_map<string, vector<int>> pos;

    int calculate(string &word1, string &word2) {
        vector<int> &pos1 = pos[word1];
        vector<int> &pos2 = pos[word2];
        int i = 0, j = 0;
        int dist = INT_MAX;
        while (i < pos1.size() && j < pos2.size()) {
            dist = min(dist, abs(pos1[i] - pos2[j]));
            if (pos1[i] > pos2[j]) 
                j++;
            else 
                i++;
        }
        return dist;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */