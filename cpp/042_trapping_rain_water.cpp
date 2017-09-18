class Solution {
public:
    // solution 1
    // remember the highest from 0 to i-1 as high[i];
    // reversely, remember the higest from i+1 to n as high_rev[i];
    // go through all the site, when the site < high and high_rev, add the difference.
    int trap(vector<int>& height) {
        int s = height.size();
        if (s < 3) return 0;
        
        vector<int> h(s, 0);
        vector<int> hr(s, 0);
        
        for (int i = 1; i < s; i++) {
            h[i] = max(height[i-1], h[i-1]);
        }
        for (int i = s - 2; i >= 0; i--) {
            hr[i] = max(height[i+1], hr[i+1]);
        }
        
        int area = 0;
        for (int i = 0; i < s; i++) {
            int m = min(h[i], hr[i]);
            if (height[i] < m)
                area += m - height[i];
        }
        
        return area;
    }
};
