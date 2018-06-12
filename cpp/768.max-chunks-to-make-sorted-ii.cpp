// two array
// left_max and right_min
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return n;
        vector<int> left_max(n, arr[0]);
        vector<int> right_min(n, arr[n - 1]);
        for (int i = 1; i < n; ++i)
            left_max[i] = max(arr[i], left_max[i - 1]);
        for (int i = n - 2; i >= 0; --i)
            right_min[i] = min(arr[i], right_min[i + 1]);
        int num = 1;    // at least 1 chunk
        for (int i = 1; i < n; ++i) {
            if (right_min[i] >= left_max[i - 1])
                ++num;
        }
        return num;
    }
};
