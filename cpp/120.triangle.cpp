class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> old(n, 0);
        vector<int> current(n, 0);
        
        for (int i = 0; i < n; i++) {
            current[0] = triangle[i][0] + old[0];
            if (i > 0)
                current[i] = triangle[i][i] + old[i - 1];
            for (int j = 1; j < i; j++) {
                current[j] = triangle[i][j] + min(old[j - 1], old[j]);
            }
            old = current;
        }
        
        int min_value = *min_element(begin(current), end(current));
        return min_value;
    }
};



// bottom up method is more concise
// from discussion
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n < 1) return 0;

        vector<int> current = triangle[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                current[j] = triangle[i][j] + min(current[j], current[j + 1]);
            }
        }
        
        return current[0];
    }
};


// O(1) space from Leetcode solution book
// but that would modify the origin matrix.
// simply use triangle[i][j] instead of a new vector