class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> freq(N, 0);
        int num = 0;
        for (char c : licensePlate) {
            int i = ctoi(c);
            if (i >= 0) {
                freq[ctoi(c)]++;
                num++;               
            }
         }
        // compare
        int len = INT_MAX;
        string result;
        for (string &w : words) {
            if (w.size() < num || w.size() >= len) continue;
            if (contain(count(w), freq)) {
                len = w.size();
                result = w;
            }
        }
        return result;
    }

private:
    const int N = 26;
    int ctoi(char &c) {
        int i = c - 'a';
        if (i >= 0 && i < N) return i;
        i = c - 'A';
        if (i >= 0 && i < N) return i;
        return -1;
    }

    vector<int> count(string &s) {
        vector<int> freq(N, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        return freq;
    }

    bool contain(const vector<int> &word, const vector<int> &plate) {
        for (int i = 0; i < N; i++) {
            if (plate[i] > word[i]) return false;
        }
        return true;
    }
};
