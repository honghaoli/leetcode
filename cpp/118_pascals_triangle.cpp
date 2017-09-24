class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};

        vector<vector<int>> result = {{1}};
        if (numRows == 1) return result;

        for (int i = 2; i <= numRows; i++) {
            result.push_back(vector<int>(i, 1));
            for (int j = 0; j < i - 2; j++) {
                result[i - 1][j + 1] = result[i - 2][j] + result[i - 2][j + 1];
            }
        }

        return result;
    }
};
