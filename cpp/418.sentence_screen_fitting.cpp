class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        N = rows;
        M = cols;
        lengths = vector<int>(sentence.size(), 0);
        total = 0;
        for (int i = 0; i < sentence.size(); ++i) {
            lengths[i] = sentence[i].size();
            if (lengths[i] > cols) return 0;
            total += lengths[i];
        }
        total += lengths.size();
        //
        num = 0;
        search(0, 0);
        return num;
    }

private:
    int total;  // total length of a whole sentence
    int N, M;   // rows, cols
    int num;    // total numbers of sentences
    vector<int> lengths;

    // start ith word, at row = r, and col = 0
    void search(int i, int r) {
        if (r >= N) return;
        int left = M;
        if (M >= total) {
            num += M / total;
            left = M % total;
        }
        while (left >= lengths[i]) {
            left -= lengths[i] + 1;
            ++i;
            if (i >= lengths.size()) {
                // finish one sentence, start from the 0th word
                i = 0;
                ++num;
            }
        }
        search(i, r + 1);
    }
};