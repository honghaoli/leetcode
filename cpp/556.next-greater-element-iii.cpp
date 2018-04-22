class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        if (stol(s) > INT_MAX || stol(s) <= n)
            return -1;
        return stoi(s);
    }
};
