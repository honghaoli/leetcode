class Solution {
public:
    // solution 1: maintain a minHeap, priority queue, with fixed k items.
    // time O(nlogk), space O(k)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto &i : nums) {
            if (minHeap.size() < k) {
                minHeap.push(i);
            } else {
                if (i > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(i);
                }
            }
        }
        return minHeap.top();
    }
};




//
class Solution {
public:
    // quick sort method, select a pivot, divide the array into smaller, equals, larger three part
    // divide and conquer
    // time O(n), space O(1) or O(logn) for recursion calls
    int findKthLargest(vector<int>& nums, int k) {
        // shuffle is important for quick sort!!
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(nums.begin(), nums.end(), g);
        //
        return divide(nums, 0, nums.size() - 1, k);
    }
    

private:
    int divide(vector<int> &nums, int start, int end, int k) {
        int pivot = start;
        int curr = start + 1, last = end;
        int start_smaller = end + 1;
        while (curr <= last) {
            if (nums[curr] > nums[pivot]) {
                swap(nums[curr], nums[pivot]);
                pivot = curr;
                curr++;
            } else if (nums[curr] < nums[pivot]) {
                swap(nums[curr], nums[last]);
                start_smaller = last;
                last--;
            } else {
                curr++;
                start_smaller = curr;
            }
        }
        
        int size_larger = pivot - start;
        int size_small_equal = start_smaller - start;
        if (k <= size_larger)
            return divide(nums, start, pivot - 1, k);
        else if (k > size_small_equal) 
            return divide(nums, start_smaller, end, k - size_small_equal);
        else
            return nums[pivot];
    }
};