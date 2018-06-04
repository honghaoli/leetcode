// straight forward O(n) solution
class MyCalendarThree {
public:
    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        int K = 0, maxK = 1;
        for (auto iter = timeline.begin(); iter != timeline.end(); ++iter) {
            K += iter->second;
            maxK = max(maxK, K);
        }
        return maxK;
    }

private:
    map<int, int> timeline;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
