class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return findNext(n, n);
    }

    vector<string> findNext(int left, int right) {
        if (left == 0) {
            string s = "";
            while (right-- > 0) {
                s += ")";
            }
            return {s};
        }

        if (right == left) {
            vector<string> result = {};
            for (auto &ns : findNext(left - 1, right))
                result.push_back("(" + ns);
            return result;
        }

        vector<string> result = {};
        for (auto &ns : findNext(left - 1, right))
            result.push_back("(" + ns);
        for (auto &ns : findNext(left, right -1))
            result.push_back(")" + ns);

        return result;
    }
};
