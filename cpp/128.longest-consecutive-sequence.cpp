class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> boundary;
        int max_length = 0;
        for (auto &n : nums) {
            if (boundary.count(n) > 0) continue;
            int left = 0, right = 0;
            if (boundary.count(n - 1) > 0) {
                left = boundary[n - 1];
            }
            if (boundary.count(n + 1) > 0) {
                right = boundary[n + 1];
            }
            int length = left + right + 1;
            max_length = max(max_length, length);
            boundary[n] = length;
            boundary[n - left] =  length;
            boundary[n + right] =  length;
        }
        return max_length;
    }
};





// another solution
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> visited;
        int max_length = 0;
        for (auto &n : nums)
            visited[n] = false;
        for (auto &n : nums) {
            if (visited[n]) continue;
            int length = 1;
            for (int j = n + 1; visited.count(j) > 0; j++) {
                visited[j] = true;
                length++;
            }
            for (int j = n - 1; visited.count(j) > 0; j--) {
                visited[j] = true;
                length++;
            }
            max_length = max(max_length, length);
        }
        return max_length;
    }
};