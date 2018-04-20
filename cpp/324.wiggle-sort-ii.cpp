class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> s(nums);
        sort(s.begin(), s.end());
        int n = s.size();
        //  M . M . M . S . S . S . S .     all even pos
        //  . L . L . L . M . M . M . M     all odd pos
        int small = 0;
        int large = (n + 1) / 2;
        for (int i = n - 1; i >= 0; i--) {
            if (i % 2 == 0)
                nums[i] = s[small++];
            else
                nums[i] = s[large++];
        }
    }
};
