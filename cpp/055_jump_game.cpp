class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start = 0, end = 0;
        int new_end = end;
        while (start <= end) {
            for (int i = start; i <= end; i++) {
                new_end = max(new_end, nums[i] + i);
                if (new_end >= nums.size() - 1) return true;                
            }
            start = end + 1;
            end = new_end;
        }
        
        if (end < nums.size() - 1)
            return false;
    }
};



class Solution {
public:
    // solution 2
    // more elegant from discussion
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return false;
        
        int reach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > reach)
                return false;
            reach = max(reach, nums[i] + i);
            if (reach >= nums.size() - 1)
                return true;
        }
    }
};
