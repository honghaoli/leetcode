// store all intervals in order
// store all double-booked intervals
// everytime add new interval, check if that overlapps with some in double-booked intervals
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        if (overlapDouble(start, end)) return false;
        pair<int, int> interval{start, end};
        chopOverlap(interval);
        intervals.push_back(interval);
        return true;
    }

private:
    // pair<int, int> is sorted automatically by first then second.
    vector<pair<int, int>> intervals;      
    vector<pair<int, int>> doubles;        // there should be no overlap in those intervals

    bool overlapDouble(int start, int end) {
        for (auto it = doubles.begin(); it != doubles.end(); ++it) {
            int s = max(start, it->first);
            int e = min(end, it->second);
            if  (s < e) return true;
        }
        return false;
    }

    void chopOverlap(pair<int, int> &interval) {
        for (auto it = intervals.begin(); it != intervals.end(); ++it) {
            int start = max(interval.first, it->first);
            int end = min(interval.second, it->second);
            if  (start < end) {
                doubles.push_back({start, end});                
            }
        }
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
