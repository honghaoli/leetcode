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




// concise
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            while (cur > 0 && cur <= nums.size() && cur != nums[cur - 1]) {
                int next = nums[cur - 1];
                nums[cur - 1] = cur;
                cur = next;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};
















// more concise solution
// swap num with nums[num - 1]
// put each number at its position
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // swap id to nums[id - 1];
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                swap(i, nums);
            }
        }
        
        // find the first num != nums[num - 1];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - 1 != i)
                return i + 1;
        }
        
        // if all the numbers exist, then return the next number larger than all of them.
        return nums.size() + 1;
    }

private:
    void swap(int i, vector<int> &nums) {
        int id = nums[i];
        nums[i] = nums[id - 1];
        nums[id - 1] = id;
    }
    
};
