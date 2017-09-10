class Solution {
public:
    bool isValid(string s) {
        // left bracket push the char into the vector, right bracket delete the char
        vector<char> left = {};
        for (int i = 0; i < s.size(); i++) {
            char &c = s[i];
            if (c == '(')
                left.push_back('(');
            else if (c == '[')
                left.push_back('[');
            else if (c == '{')
                left.push_back('{');
            else {
                if (left.size() < 1)
                    return false;
                else if (c == ')') {
                    if (left.back() != '(')
                        return false;
                    left.pop_back();
                }
                else if (c == ']') {
                    if (left.back() != '[')
                        return false;
                    left.pop_back();
                }
                else if (c == '}') {
                    if (left.back() != '{')
                        return false;
                    left.pop_back();
                }
            }
        }

        if (left.size() == 0)
            return true;
        else
            return false;
    }
};
