class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix.at(0).size();
        if (n == 0) return {};
        
        // direct
        // 0: left to right;
        // 1: top to bottom;
        // 2: right to left;
        // 3: bottom to top;
        int direct = 0;
        // the boundary at left, right, top and bottom
        int l = 0, r = n - 1;
        int t = 0, b = m - 1;
        
        vector<int> result;
        int i = 0, j = 0, count = 0;
        
        while (count++ < m * n) {
            result.push_back(matrix[i][j]);
            if (direct == 0) {
                if (j < r) {
                    j++;
                } else {
                    direct = 1;
                    t++;
                    i++;
                }
            } else if (direct == 1) {
                if (i < b) {
                    i++;
                } else {
                    direct = 2;
                    r--;
                    j--;
                }
            } else if (direct == 2) {
                if (j > l) {
                    j--;
                } else {
                    direct = 3;
                    b--;
                    i--;
                }
            } else if (direct == 3) {
                if (i > t) {
                    i--;
                } else {
                    direct = 0;
                    l++;
                    j++;
                }
            }
        }
        
        return result;
    }
};
