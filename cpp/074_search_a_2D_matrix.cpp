class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n < 1) return false;
        int m = matrix[0].size();
        if (m < 1) return false;
        
        int lo = 0, hi = n * m - 1;
        int mid, i, j;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            tie(i, j) = ids(mid, m);
            if (target < matrix[i][j]) {
                hi = mid - 1;
            } else if (target > matrix[i][j]) {
                lo = mid + 1;
            } else {
                return true;
            }
        }
        
        return false;
    }
    
    pair<int, int> ids(int i, int m) {
        return make_pair(i / m, i % m);
    }
};
