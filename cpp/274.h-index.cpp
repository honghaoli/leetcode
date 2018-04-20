class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        // count each citation number
        vector<int> count(n + 1, 0);
        for (int &c : citations) {
            if (c < n)
                count[c]++;
            else
                count[n]++;
        }
        // sum from the end
        if (count[n] >= n) 
            return n;
        for (int i = n - 1; i >= 0; i--) {
            count[i] += count[i + 1];
            if (count[i] >= i) 
                return i;
        }
        // never here
        return 0;
    }
};
