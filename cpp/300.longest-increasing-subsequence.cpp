// according to:
// https://en.wikipedia.org/wiki/Longest_increasing_subsequence
// time O(n logn), space O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        vector<int> M(n + 1, 0);    // M[j]: for length of j subsequence, the index of the end number
        vector<int> P(n, 0);        // P[i]: parent number index for the subsequence with end number is nums[i]
        int L = 0;                  // max length
        for (int i = 0; i < n; i++) {
            // binary search the largest ss length with end number < nums[i];
            int lo = 1;             // min length = 1, not 0
            int hi = L;
            while (lo <= hi) {
                // mid = ceil((hi + lo) / 2) ???
                int mid = (hi - lo) / 2 + lo;
                if (nums[M[mid]] < nums[i])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            // now lo is the largest possible value that nums[M[lo - 1]] < nums[i] 
            // int newL = lo;
            M[lo] = i;              // new max L end with index i
            P[i] = M[lo - 1];       // parent node for i is lo - 1
            L = max(L, lo);         // update max length L
        }
        // // if we want to reconstruct the subsequence
        // vector<int> seq(L, 0);
        // int p = M[L];
        // for (int l = L; l > 0; l--) {
        //     seq[l - 1] = nums[p];
        //     p = P[p]
        // }
        return L;
    }
};
