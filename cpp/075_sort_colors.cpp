class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) return;
        
        int n0 = 0, n1 = 0, n2 = 0;
 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                n0++;
            else if (nums[i] == 1)
                n1++;
            else
                n2++;
        }
 
        for (int i = 0; i < n0; i++)
            nums[i] = 0;        
        for (int i = 0; i < n1; i++)
            nums[n0 + i] = 1;        
        for (int i = 0; i < n2; i++)
            nums[n0 + n1 + i] = 2;
        
    }
};



// one pass
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) return;
        
        int start = 0, end = nums.size() - 1;
        int mid = 0;
        
        while (mid <= end) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[start]);
                start++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else if (nums[mid] == 2) {
                swap(nums[mid], nums[end]);
                end--;
            }
        }
        
    }
};
