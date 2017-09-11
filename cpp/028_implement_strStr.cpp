class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        if (needle.size() > haystack.size())
            return -1;

        bool found = false;
        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            found = true;
            for (int j = 0; j < needle.size(); j++) {
                if (needle[j] != haystack[i + j]) {
                    found = false;
                    break;
                }
            }

            if (found)
                return i;
        }

        return -1;
    }
};
