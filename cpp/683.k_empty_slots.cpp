// Problem
// There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.
// Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.
// For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.
// Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.
// If there isn't such day, output -1.
// Example 1:
// Input: 
// flowers: [1,3,2]
// k: 1
// Output: 2
// Explanation: In the second day, the first and the third flower have become blooming.
// Example 2:
// Input: 
// flowers: [1,2,3]
// k: 1
// Output: -1
// Note:
// The given array will be in the range [1, 20000].


// improved O(N) solution
// ref:
// https://leetcode.com/problems/k-empty-slots/discuss/107931/JavaC++-Simple-O(n)-solution
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        vector<int> days(flowers.size(), 0);
        for (int i = 0; i < flowers.size(); ++i)
            days[flowers[i] - 1] = i + 1;
        int left = 0, right = left + k + 1;
        int min_day = INT_MAX;
        while (right < days.size()) {
            for (int i = left + 1; i <= right; ++i) {
                if (i == right) {
                    min_day = min(min_day, max(days[left], days[right]));
                    left = right;
                    right = left + k + 1;
                    break;
                } else if (days[i] < days[left] || days[i] < days[right]) {
                    // start from the new minimum point
                    left = i;
                    right = left + k + 1;
                    break;
                }
            }
        }
        return min_day == INT_MAX ? -1 : min_day;

    }
};



// Use a ordered set to store all the blooming flowers
// each insertion ~ O(log N)
// then find the nearby two flowers' positions, compare with k.
// total time ~O(N log N)

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> pos;
        for (int i = 1; i <= flowers.size(); ++i) {
            int f = flowers[i - 1];
            pos.insert(f);
            auto iter = pos.find(f);
            auto prev = iter;
            auto next = iter;
            if (iter != pos.begin() && f - *(--prev) == k + 1)  return i;
            if ((++next) != pos.end() && *next - f == k + 1)  return i;
        }
        return -1;
    }
};