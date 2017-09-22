class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        
        int direct = 0;
        int l = 0, r = n - 1;
        int t = 0, b = n - 1;
        int count = 0;
        int i = 0, j = 0;
        while (count++ < n * n) {
            result[i][j] = count;
            
            if (direct == 0) {
                if ( j < r) {
                    j++;
                } else {
                    direct = 1;
                    i++;
                    t++;
                }
            } else if (direct == 1) {
                if ( i < b) {
                    i++;
                } else {
                    direct = 2;
                    j--;
                    r--;
                }
            } else if (direct == 2) {
                if ( j > l) {
                    j--;
                } else {
                    direct = 3;
                    i--;
                    b--;
                }
            } else if (direct == 3) {
                if ( i > t) {
                    i--;
                } else {
                    direct = 0;
                    j++;
                    l++;
                }
            }
        }
        
        return result;
    }
