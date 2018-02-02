class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n < 1) return 0;

        int max_area = 0;
        int i = 0;
        vector<int> stack;
        while (i < n) {
            if (stack.empty() || heights[i] > heights[stack.back()]) {
                stack.push_back(i);
                i++;
            } else {
                int top = stack.back();
                stack.pop_back();
                int area = heights[top] * (stack.empty()? i : i - stack.back() - 1);
                max_area = max(area, max_area);
            }
        }

        // then pop out all the remaining bars
        while (!stack.empty()) {
            int top = stack.back();
            stack.pop_back();
            int area = heights[top] * (stack.empty() ? i : i - stack.back() - 1);
            max_area = max(area, max_area);
        }

        return max_area;
    }
};
