class Solution {

public:
    bool isNumber(string s) {
        int i = 0, j = s.size() - 1;
        // trim space at front/back
        while (i <= j && s[i] == ' ') {
            i++;
        }
        while (i <= j && s[j] == ' ') {
            j--;
        }
        cout << i << ", " << j << endl;
        // if nothing left
        if (j < i) return false;

        int pos_dot = findDot(s, i, j);
        int pos_e = findE(s, i, j);
        cout << pos_dot << ", " << pos_e << endl;
        if (pos_dot == -2) return false;       // more than one "."
        if (pos_e == -2 || pos_e == 0) return false;          // more than one "e"
        if (pos_e > 0 && pos_dot > pos_e) return false;     // "." must be before "e"

        bool cond1 = isValidBeforeE(s, i, j);
        bool cond2 = isValidBeforeE(s, i, pos_e - 1);
        bool cond3 = isValidAfterE(s, pos_e + 1, j);
        cout << cond1 << ", " << cond2 << ", " << cond3 << endl;

        if (pos_e < 0 && isValidBeforeE(s, i, j))
            return true;
        else if (isValidBeforeE(s, i, pos_e - 1) && isValidAfterE(s, pos_e + 1, j))
            return true;
        else
            return false;
    }


private:
    int findDot(string &s, int i, int j)  {
        int id = -1;
        for (int k = i; k <= j; k++) {
            if (s[k] == '.') {
                if (id < 0)
                    id = k;
                else
                    return -2;      // find multiple "."
            }
        }
        return id;
    }

    int findE(string &s, int i, int j) {
        int id = -1;
        for (int k = i; k <= j; k++) {
            if (s[k] == 'e') {
                if (id < 0)
                    id = k;
                else
                    return -2;      // find multiple "e"
            }
        }
        return id;
    }

    bool isValidAfterE(string &s, int start, int end) {
        if (end < start) return false;
        if (end == start) {
            if (isDigit(s[start])) return true;
            else return false;
        }
        if (!isDigit(s[start]) && s[start] != '-' && s[start] != '+') return false;
        for (int k = start + 1; k <= end; k++) {
            if (!isDigit(s[k])) return false;
        }
        return true;
    }

    bool isValidBeforeE(string &s, int start, int end) {
        if (end < start) return false;
        if (end == start) {
            if (isDigit(s[start])) return true;
            else return false;
        }

        bool hasDigit = false;
        if (isDigit(s[start]))
                hasDigit = true;
            else if (s[start] != '-' && s[start] != '+' && s[start] != '.')
                return false;

        for (int k = start + 1; k <= end; k++) {
            if (isDigit(s[k]))
                hasDigit = true;
            else if (s[k] != '.')
                return false;
        }
        return hasDigit;
    }

    bool isDigit(char &c) {
        if (c >= 48 && c <= 57) return true;
        else return false;
    }
};






// second method.
// inspire by the discussion on leetcode
class Solution {
public:
    bool isNumber(string s) {
        int i = 0, j = s.size() - 1;
        // trim the string first
        for (; i <= j && s[i] == ' '; i++);
        for (; i <= j && s[j] == ' '; j--);
        if (j < i) return false;        // nothing left
        //
        bool foundDigit = false;
        bool foundDot = false;
        bool foundExp = false;
        //
        for (int k = i; k <= j; k++) {
            if (s[k] >= '0' && s[k] <= '9') {
                foundDigit = true;
            } else if (s[k] == 'e') {
                if (foundExp) 
                    return false;     // more than one 'e'
                else {
                    if (!foundDigit) return false;      // must have number before 'e'.
                    foundExp = true;
                    foundDigit = false;
                }
            } else if (s[k] == '.') {
                if (foundDot || foundExp)
                    return false;       // more than one '.', or '.' after 'e'
                else {
                    foundDot = true;                         
                }
            } else if (s[k] == '+' || s[k] == '-') {
                if (k != i && s[k - 1] != 'e')
                    return false;       // +- can only be the first or the one after 'e'
            } else {
                // not valid symbol
                return false;
            }
        }
        
        return foundDigit;
    }
};








/* Some test Cases

    "e9"
    "46.e3"
    " -."
    "123",
    " 123 ",
    "0",
    "0123",
    "00",
    "-10",
    "-0",
    "123.5",
    "123.000000",
    "-500.777",
    "0.0000001",
    "0.00000",
    "0.",
    "00.5",
    "123e1",
    "1.23e10",
    "0.5e-10",
    "1.0e4.5",
    "0.5e04",
    "12 3",
    "1a3",
    "",
    "     ",
    null,
    ".1",
    ".",
    "2e0",
    "+.8",
    " 005047e+6",

*/
