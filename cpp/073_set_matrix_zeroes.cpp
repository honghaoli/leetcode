class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n < 1) return;
        int m = matrix[0].size();
        if (m < 1) return;
        
        bool row0 = false;
        bool col0 = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0)
                        row0 = true;
                    if (j == 0)
                        col0 = true;
                    else {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
        }
        
        for (int i = 1; i < n; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < m; j++)
                    matrix[i][j] = 0;
            }
        }
        
        for (int j = 1; j < m; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < n; i++)
                    matrix[i][j] = 0;
            }
        }

        if (col0)
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
        if (row0)
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;
    }
};
