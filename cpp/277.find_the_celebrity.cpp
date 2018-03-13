// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if (n < 2) return -1;
        int l = 0, r = n - 1;
        while (l < r) {
            if (knows(l, r)) l++;
            else r--;
        }
        // now l == r is the candidate
        for (int i = 0; i < n; i++) {
            if (i == l) continue;
            if (knows(l, i) || !knows(i, l)) return -1;
        }

        return l;
    }
};