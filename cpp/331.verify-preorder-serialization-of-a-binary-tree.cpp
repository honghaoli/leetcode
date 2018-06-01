// first root, then we need 2 #
// every time add a number, we need one more #
// every time add a #, we substract the number of # needed.
// keep track of the number of #,
// at the end, there should be total 0 # left.
// Time O(n)
class Solution {
public:
    bool isValidSerialization(string preorder) {
        s = preorder;
        index = 0;
        int null_needed = 1;
        while (index < s.size()) {
            string node = next_node();
            if (node == "") break;
            else if (node == "#") {
                null_needed--;
                if (null_needed < 0) return false;
            } else {
                // it's a number
                if (null_needed <= 0) return false;
                int num = stoi(node);
                null_needed++;
            }
        }
        return null_needed == 0;
    }

private:
    int index;
    string s;

    string next_node() {
        if (index >= s.size()) return "";
        int end = index + 1;
        while (end < s.size() && s[end] != ',')
            end++;
        string result = s.substr(index, end - index);
        index = end + 1;
        return result;
    }
};

