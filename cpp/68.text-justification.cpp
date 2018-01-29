class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        if (n < 1) return words;

        int s = 0, e = 0;
        vector<string> result;
        while (e < n) {
            // find which words will be in this line.
            int total = words[s].size();
            string line = words[s];
            for (e = s + 1; e < n; e++) {
                if (total + words[e].size() + 1 > maxWidth)
                    break;
                else
                    total += words[e].size() + 1;
            }
            int extra = maxWidth - total;
            // if only one word
            if (e - s == 1) {
                line.append(string(maxWidth - line.size(), ' '));
                result.push_back(line);
            } else if (e < n) {     // not the last line
                // calculate space
                int base = extra / (e - s - 1);
                int more = extra % (e - s - 1);
                // start to pack
                for (int k = s + 1; k < e; k++) {
                    if (k - s <= more)
                        line.append(string(base + 2, ' ') + words[k] );
                    else
                        line.append(string(base + 1, ' ') + words[k] );
                }
                result.push_back(line);
            } else {
                // last line, no extra space, all words are left aligned.
                for (int k = s + 1; k < e; k++) {
                    line.append(" " + words[k]);
                }
                line.append(string(extra, ' '));
                result.push_back(line);
            }
            // reset start and end point
            s = e;
            e = s;
        }

        return result;
    }
};
