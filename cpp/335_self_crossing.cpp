class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int s = x.size();
        if (s <= 3) return false;
        
        if (s >= 5) {
            // for case [1,1,2,1,1]
            // 5 > (3-1) and 4 == 2.
            if (x[4] >= x[2] - x[0] && x[3] == x[1]) {
                cout << "head" << endl;
                return true;
            }
        }
        
        for (int i = 3; i < s; i++) {
            // if 4 > 2 && 3 < 1, cross
            if (x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) {
                cout << "first: " << i << endl;
                return true;
            }
            // for circle larger and larger case:
            // when 3 > 5 > (3-1) and 6 > (4-2), cross
            if (i >= 5 && x[i-3] >= x[i-5] && x[i-2] >= x[i-4] && x[i-1] <= x[i-3] && x[i - 1] >= x[i - 3] - x[i - 5] && x[i] >= x[i - 2] - x[i - 4]) {
                cout << "second: " << i << endl;
                return true;
            }
        }
        
        return false;
    }
};
