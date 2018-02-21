class Solution {
public:
    // solution 1
    // move the m numbers to the back part of nums1 vector
    // then choose the min of nums1 and nums2 head, place it in the front.
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // move the m numbers to the back
        for (int i = m - 1; i >= 0; i--) {
            nums1[i + n] = nums1[i];
        }

        // compare two heads, choose the smaller
        int p1 = n, p2 = 0;
        int id = 0;
        while (p2 < n && p1 < m + n) {
            if (nums1[p1] < nums2[p2]) {
                nums1[id] = nums1[p1];
                p1++;
                id++;
            } else {
                nums1[id] = nums2[p2];
                p2++;
                id++;
            }
        }

        // in case nums2 left several numbers
        while (p2 < n) {
            nums1[id] = nums2[p2];
            p2++;
            id++;
        }
    }
};







// more concise
// merge from back to front
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cur = m + n - 1;
        int i1 = m - 1, i2 = n - 1;
        // merge from back to front
        while (i1 >= 0 && i2 >= 0) {
            if (nums1[i1] > nums2[i2]) {
                nums1[cur--] = nums1[i1];
                i1--;
            } else {
                nums1[cur--] = nums2[i2];
                i2--;
            }
        }
        // in case trailing nums2 left.
        while (i2 >= 0) {
            nums1[cur--] = nums2[i2];
            i2--;
        }
    }
};