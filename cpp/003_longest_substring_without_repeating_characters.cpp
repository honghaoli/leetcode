
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        if (s.size() == 1)
            return 1;

        int start = 0, end = 0;
        int length = 0, max_length = 0;
        // use a hashmap to store each char's position, to check duplicate.
        //unordered_map<char, int> hashmap;
        vector<int> hashmap(256, -1);

        for (end = 0; end < s.size(); end++) {
            char &c = s[end];
            //if (hashmap.count(c) > 0 && hashmap[c] >= start) {     // exist in current substring
            if (hashmap[c] >= start) {
                start = hashmap[c] + 1;
            }

            length = end - start + 1;
            if (length > max_length)
                max_length = length;

            hashmap[c] = end;
        }

        return max_length;
    }
};
