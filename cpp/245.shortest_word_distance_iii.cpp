class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if (word1 == word2) 
            return distSame(words, word1);

        int pos1 = -1, pos2 = -1;
        int dist = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                pos1 = i;
                if (pos2 >= 0)
                    dist = min(dist, pos1 - pos2);
            }
            if (words[i] == word2) {
                pos2 = i;
                if (pos1 >= 0)
                    dist = min(dist, pos2 - pos1);
            }
        }
        if (dist < INT_MAX)
            return dist;
        else
            return -1;
    }

    int distSame(vector<string> &words, string &word) {
        int pos1 = -1;
        int dist = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word) {
                if (pos1 >= 0)
                    dist = min(dist, i - pos1);
                pos1 = i;
            }
        }
        if (dist < INT_MAX)
            return dist;
        else
            return -1;
    }
};