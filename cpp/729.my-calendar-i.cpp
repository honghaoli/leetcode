class MyCalendar {
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        if (start >= end) return false;
        if (!isEmpty(start, end)) return false;
        intervals.insert(make_pair(start, end));
        return true;
    }

private:
    set<pair<int, int>> intervals;

    bool isEmpty(int start, int end) {
        if (intervals.size() == 0) return true;
        // auto iter = upper_bound(intervals.begin(), intervals.end(), make_pair(start, end));
        // the above line is much slower!
        auto iter = intervals.upper_bound(make_pair(start, end));
        if (iter != intervals.end() && iter->first < end) return false;
        if (iter != intervals.begin() && (--iter)->second > start) return false;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */

