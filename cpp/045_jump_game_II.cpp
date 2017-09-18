class Solution {
public:
    // from beginning to end, record the furthest place this time can jump, until reaches the end.
    // record the total time/level.
    int jump(vector<int>& nums) {
        int s = nums.size();
        if (s <= 1) return 0;
        
        int level = 0;
        int start = 0, end = 0;
        while (end < s - 1) {
            level++;
            int new_end = end;
            for (int i = start; i <= end; i++) {
                new_end = max(new_end, nums[i] + i);
                if (new_end >= s - 1) break;
            }
            start = end + 1;
            end = new_end;
        }
        
        return level;
    }

};
