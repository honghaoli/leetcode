class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // change all negative values to 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0)
                nums[i] = 0;
        }
        
        // for each positive num, mark nums[num] = -1, means this number exists.
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                mark(nums[i], nums);
        }

        // find the first num that is not -1, means this number does not exist.
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != -1)
                return i + 1;
        }
        
        // if all the numbers exist, then return the next number larger than all of them.
        return nums.size() + 1;
    }

private:
    void mark(int n, vector<int> &nums) {
        // number 1 would be put at nums[0],  number n would be put at nums[n-1]
        int id = n - 1;
        if (id < 0 || id >= nums.size()) return;
        // change this nums[n-1] = -1, then recursively change mark the next nums[nums[n-1]].
        // this process cannot be inverted, otherwise there are infinite loop if a circle exist:
        // for example, [1], set the first to be -1 would recursively call itself;
        // or [2, 1], set [2] to be -1 would first set [1] to be -1, which will set [2] to be -1 too, infinite loop. 
        int tmp = nums[id];
        nums[id] = -1;
        if (tmp > 0)
            mark(tmp, nums);
    }
    
    void print_vector(vector<int> &nums) {
        for (auto &i : nums)
            cout << i << ", ";
        cout << endl;
    }
};
