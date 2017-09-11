class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();

        // find the first place to fill.
        int toFill = 1;
        while(toFill < nums.size() && nums[toFill] > nums[toFill - 1])
            toFill++;

        int toCompare = toFill + 1;
        while (toCompare < nums.size()) {
            while (toCompare < nums.size() && nums[toCompare] <= nums[toFill - 1]) {
                toCompare++;
            }
           if (toCompare >= nums.size())
                return toFill;
            nums[toFill] = nums[toCompare];
            toFill++;
            toCompare++;
        }

        return toFill;
    }
};







// solution

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();

        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] > nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
