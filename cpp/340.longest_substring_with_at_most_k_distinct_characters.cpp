class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int i = 0, j = 0;
        int max_length = 0;
        unordered_map<char, int> freq;
        // end index
        while (j < s.size()) {
            // if this char is new
            if (freq.count(s[j]) == 0) {
                freq[s[j]] = 1;
                // increment i if the substring has more than k distinct chars.
                while (freq.size() > k) {
                    freq[s[i]]--;
                    if (freq[s[i]] == 0) {
                        freq.erase(s[i]);
                    }
                    i++;
                }
            } else {
                // if this char already exists in the hashmap
                freq[s[j]]++;
            }
            // update the max length
            max_length = max(max_length, j - i + 1);
            // move to next char
            j++;
        }
        return max_length;
    }
};