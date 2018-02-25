class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        N = 0;
    }
    
    void addNum(int num) {
        N++;
        if (minHeap.empty()) {
            minHeap.push(num);
        } else {
            if (num >= minHeap.top()) {
                minHeap.push(num);
            } else {
                maxHeap.push(num);
            }
            // balance two heaps
            if (minHeap.size() > maxHeap.size() + 1) {
                int m = minHeap.top();
                minHeap.pop();
                maxHeap.push(m);
            } else if (minHeap.size() < maxHeap.size()) {
                int m = maxHeap.top();
                maxHeap.pop();
                minHeap.push(m);
            }
        }
    }
    
    double findMedian() {
        if (N % 2 == 1) {
            return minHeap.top() * 1.0;
        } else {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
    }
    
private:
    // two heaps:
    // max-heap for values below the median;    always has 0 or 1 more items
    // min-heap for values above the median;
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int N;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */