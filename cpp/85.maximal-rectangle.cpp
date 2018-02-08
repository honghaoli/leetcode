class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n < 1) return 0;
        int m = matrix[0].size();
        vector<int> row(m, 0);
        
        int max_value = 0;
        for (int i = 0; i < n; i++) {
            // calculate accumulate sum
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    row[j] = 0;
                } else {
                    row[j] += 1;
                }
            }
            // find the max rectangle in histogram
            max_value = max(max_value, maxRectangleInHistogram(row));
        }
        
        return max_value;
    }
    

private:
    int maxRectangleInHistogram(vector<int> &row) {
        vector<int> stack;
        int max_rect = 0;
        int i = 0;
        while (i < row.size()) {
            if (stack.empty() || row[i] >= row[stack.back()]) {
                stack.push_back(i);
                i++;
            } else {
                if (!stack.empty()) {
                    int hi = stack.back();
                    int h = row[hi];
                    stack.pop_back();
                    int w = stack.empty() ? i : (i - stack.back() - 1);
                    max_rect = max(max_rect, h * w);
                }
            }
        }
        
        while (!stack.empty()) {
            int hi = stack.back();
            int h = row[hi];
            stack.pop_back();
            int w = stack.empty() ? i : (i - stack.back() - 1);
            max_rect = max(max_rect, h * w);
        }
        
        return max_rect;
    }
};