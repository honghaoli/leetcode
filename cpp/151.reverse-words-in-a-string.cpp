
class Solution {
public:
    void reverseWords(string &s) {
        // remove extra spaces
        int start = 0;
        bool had_space = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (had_space) 
                    continue;
                else {
                    had_space = true;
                    s[start++] = s[i];
                }
            } else {
                had_space = false;
                s[start++] = s[i];
            }
        }
        // now size = start
        s.erase(s.begin() + start, s.end());
        // in case the last char is empty
        if (s.size() > 0 && s.back() == ' ')
            s.erase(s.end() - 1, s.end());

        // reverse each word
        start = 0;
        int end = 0;
        while (end < s.size()) {
            // find the end of this word
            while (end < s.size() && s[end] != ' ') end++;
            // reverse the word
            reverse(s.begin() + start, s.begin() + end);
            // find the start of next word
            end++;
            start = end;
        }

        // reverse the whole sentence
        reverse(s.begin(), s.end());
    }
};


