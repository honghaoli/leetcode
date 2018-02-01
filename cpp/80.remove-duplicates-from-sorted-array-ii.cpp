// this concise solution is inspired by the solution of previous problem: Remove Duplicates
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//       if (nums.size() < 1) return 0;
//
//       int i = 0, j = 1;
//       int freq = 1;
//
//       for (int j = 1; j < nums.size(); j++) {
//         if (nums[j] == nums[i] && freq < 2) {
//           i++;
//           nums[i] = nums[j];
//           freq++;
//         } else if (nums[j] > nums[i]) {
//           i++;
//           nums[i] = nums[j];
//           freq = 1;
//         }
//       }
//
//       return i + 1;
//     }
// };



// the following solution is much conciser!!!!
// inspired by the discussion
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int i = 0;
      for (auto &n : nums) {
        if (i < 2 || n > nums[i - 2]) {
          nums[i] = n;
          i++;
        }
      }

      return i;
    }
};
