class Solution {
public:
    // each group of four points rotate like:
    // i, j ===>  j, n-i  ===> n-i, n-j  ===> n-j, i ===> i, j
    // be careful with all those n and n-1 boundary cases!!!
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() < 2) return;
        
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i]= matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = tmp;
            }
        }
    }
};
