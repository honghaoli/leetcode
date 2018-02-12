// recursion version
// not fast enough 
class Solution {
public:
    bool isScramble(string s1, string s2) {
        return isScramble(s1, 0, s1.size(), s2, 0, s2.size());
    }
    

private:
    const int num_chars = 128;      // assume ASCII
    
    // string[start, end)
    bool isScramble(string &s1, int start1, int end1, string &s2, int start2, int end2) {
        if (end1 - start1 != end2 - start2) return false;
        if (end1 - start1 == 0) return true;
        vector<int> chars1(num_chars, 0);
        vector<int> chars2(num_chars, 0);
        bool identical = true;
        for (int i = 0; i < end1 - start1; i++) {
            if (s1[i + start1] != s2[i + start2]) identical = false;
            chars1[s1[i + start1]]++;
            chars2[s2[i + start2]]++;
        }
        if (identical) return true;
        for (int i = 0; i < num_chars; i++) {
            if (chars1[i] != chars2[i]) return false;
        }
        // recursion
        for (int i = 1; i < end1 - start1; i++) {
            bool left_left = isScramble(s1, start1, start1 + i, s2, start2, start2 + i);
            bool right_right = isScramble(s1, start1 + i, end1, s2, start2 + i, end2);
            if (left_left && right_right) return true;
            bool left_right = isScramble(s1, start1, start1 + i, s2, end2 - i, end2);
            bool right_left = isScramble(s1, start1 + i, end1, s2, start2, end2 - i);
            if (left_right && right_left) return true;
        }
        
        return false;
    }
};