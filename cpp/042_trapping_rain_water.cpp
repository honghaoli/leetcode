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







class Solution {
public:
    // solution 1
    // remember the highest from 0 to i-1 as high[i];
    // reversely, remember the higest from i+1 to n as high_rev[i];
    // go through all the site, when the site < high and high_rev, add the difference.
    //
    // solution 2
    // we dont need the extra O(n) space, just remember the highest.
    int trap(vector<int>& height) {
        int s = height.size();
        if (s < 3) return 0;
        
        int area = 0;
        int left = 0, right = s - 1;
        int max_left = height[left], max_right = height[right];
        
        while (left < right) {
            if (max_right > max_left) {
                left++;
                if (height[left] < max_left)
                    area += max_left - height[left];
                else
                    max_left = height[left];
            } else {
                right--;
                if (height[right] < max_right)
                    area += max_right - height[right];
                else
                    max_right = height[right];
            }
        }

        return area;
    }
};
