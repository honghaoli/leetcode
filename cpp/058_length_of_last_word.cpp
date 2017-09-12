class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int pre = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (length > 0)
                    pre = length;
                length = 0;
            } else {
                length++;
            }
        }

        if (length == 0)
            return pre;
        return length;
    }
};
