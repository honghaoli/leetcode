class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        iter.push_back(v1.begin());
        ends.push_back(v1.end());
        iter.push_back(v2.begin());
        ends.push_back(v2.end());
        row = 0;
    }

    int next() {
        int result = *iter[row]; 
        ++iter[row];
        row = (row + 1) % iter.size();
        return result;
    }

    bool hasNext() {
        int r = row;
        while (iter[r] == ends[r]) {
            // end of the r-th vector
            r = (r + 1) % iter.size();
            if (r == row) return false;     // come back after a round.
        }
        row = r;
        return true;
    }

private:
    int row;
    vector<vector<int>::iterator> iter;
    vector<vector<int>::iterator> ends;
};










// the following solution is not Iterator solution!!!
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        data.push_back(v1);
        data.push_back(v2);
        row = 0;
        col = 0;
    }

    int next() {
        int result = data[row][col];
        row = (row + 1) % data.size();
        if (row == 0)
            ++col;
        return result;
    }

    bool hasNext() {
        if (data.size() == 0) 
            return false;
        int r = row;
        while (col >= data[r].size()) {
            ++r;
            if (r >= data.size()) {
                r = 0;
                ++col;
            }
            if (r == row) 
                return false; // come back after a round
        }
        row = r;    // update to new position
        return true;
    }

private:
    int row, col;
    vector<vector<int>> data;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */