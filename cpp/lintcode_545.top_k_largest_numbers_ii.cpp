class Solution {
public:
    /*
    * @param k: An integer
    */Solution(int k) : k(k) {
        // do intialization if necessary
    }

    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {
        // write your code here
        if (minHeap.size() < k)
            minHeap.push(num);
        else if (num > minHeap.top()) {
            minHeap.push(num);
            minHeap.pop();
        }
    }

    /*
     * @return: Top k element
     */
    vector<int> topk() {
        // get a copy
        auto c = minHeap;
        vector<int> result;
        while (!c.empty()) {
            result.push_back(c.top());
            c.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};