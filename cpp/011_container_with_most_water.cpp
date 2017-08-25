class Solution {
public:
    // algorithm from the solution
    int maxArea(vector<int>& height) {
        int area = 0;
        int start = 0, end = height.size() - 1;
        while (start < end) {
            int a = min(height[start], height[end]) * (end - start);
            if (a > area)
                area = a;
            // move the short line
            if (height[start] < height[end])
                start++;
            else
                end--;
        }
        return area;
    }
};
