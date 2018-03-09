// naive method that splits matrix into three parts
// time O( (n*m)^log_4^3 )
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() < 1 || matrix[0].size() < 1) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        return search(matrix, 0, m - 1, 0, n - 1, target);
    }

private:
    bool search(vector<vector<int>> &matrix, int r1, int r2, int c1, int c2, int target) {
        if (r1 > r2 || c1 > c2) return false;
        int r = r1 + (r2 - r1) / 2;
        int c = c1 + (c2 - c1) / 2;
        if (target == matrix[r][c]) {
            return true;
        } else if (target > matrix[r][c]) {
            if (search(matrix, r + 1, r2, c + 1, c2, target))
                return true;
            if (search(matrix, r + 1, r2, c1, c, target))
                return true;
            if (search(matrix, r1, r, c + 1, c2, target))
                return true;
        } else {
            if (search(matrix, r1, r - 1, c1, c - 1, target))
                return true;
            if (search(matrix, r1, r - 1, c, c2, target))
                return true;
            if (search(matrix, r, r2, c1, c - 1, target))
                return true;
        }
        return false;
    }
};


// better solution with time O(n + m)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m < 1) return false;
        int n = matrix[0].size();
        if (n < 1) return false;
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) j--;
            else if (matrix[i][j] < target) i++;
        }
        return false;
    }
};
