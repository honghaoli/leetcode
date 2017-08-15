#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = num1.size();
        int n2 = num2.size();
        // boundary check
        if (n1 + n2 <= 0) {
            // throw exception
        }
        // empty check
        if (n1 == 0)
            return findMedianForOneArray(nums2);
        if (n2 == 0)
            return findMedianForOneArray(nums1);
        // make sure n1 <= n2
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);


        // general case
        int lo = 0, hi = n1;
        int imid, j;
        while (lo <= hi) {
            imid = (lo + hi) / 2;
            j = (n1 + n2 + 1) / 2 - imid;
            if (imid < n1 && nums1[imid] < nums2[j-1]) {
                lo = imid + 1;
                continue;
            } else if (imid > 0 && nums1[imid-1] > nums2[j]) {
                hi = imid;
                continue;
            } else {
                // found the correct i and j
                // include the case where i or j = 0 or > size.
                break;
            }
        }

        int max_left, min_right;
        if (imid == 0)
            max_left = nums2[j-1];
        else if (j == 0)
            max_left = nums1[imid-1];
        else
            max_left = max(nums1[imid-1], nums2[j-1]);

        if (imid == n1)
            min_right = nums2[j];
        else if (j == n2)
            min_right = nums1[imid];
        else
            min_right = min(nums1[imid], nums2[j]);

        if ((n1 + n2) % 2 == 0)
            return static_cast<double>(max_left + min_right) / 2.0;
        else
            return static_cast<double>(max_left + min_right);

    }

private:
    double findMedianForOneArray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) {
            // throw exception
        }
        // even
        if (n % 2 == 0) {
            return static_cast<double>(nums[n/2] + nums[n/2 - 1]) / 2.0;
        } else {
            // odd
            return static_cast<double>(nums[(n-1)/2]);
        }
    }


};
