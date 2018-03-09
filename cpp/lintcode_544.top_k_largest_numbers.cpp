class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        // priority queue
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto &n : nums) {
            if (minHeap.size() < k)
                minHeap.push(n);
            else {
                if (n > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(n);
                }
            }
        }
        
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};