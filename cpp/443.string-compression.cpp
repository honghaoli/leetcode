class Solution {
public:
    int compress(vector<char>& chars) {
        char last = ' ';
        int count = 0;
        int p = 0;
        for (char &c : chars) {
            if (c != last) {
                if (count > 1) {
                    string num = to_string(count);
                    for (char &n : num) {
                        chars[p++] = n;
                    }
                }
                chars[p++] = c;
                count = 1;
                last = c;
            } else {
                count++;
            }
        }
        if (count > 1) {
            string num = to_string(count);
            for (char &n : num) {
                chars[p++] = n;
            }
        }
        return p;
    }
};
