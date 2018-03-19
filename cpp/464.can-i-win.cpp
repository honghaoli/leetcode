class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int &n = desiredTotal;
        int &m = maxChoosableInteger;
        if (n <= m) return true;

        vector<int> seq(m, 0);
        for (int i = 0; i < m; i++)
            seq[i] = i + 1;

        return (whoWin(seq, 0, 0, n) == 1);
    }

private:
    bool mayLose(vector<int> &seq, int start, int pre_sum, int target) {
        if (start % 2 == 1) {
            // 2nd player's turn
            for (int i = start; i < seq.size(); i++) {
                if (pre_sum + seq[i] >= target) return true;
            }
            for (int i = start; i < seq.size(); i++) {
                swap(seq[start], seq[i]);
                if (mayLose(seq, start + 1, pre_sum + seq[start], target))
                    return true;
                swap(seq[start], seq[i]);
            }
            return false;
        } else {
            // 1st player's turn
            for (int i = start; i < seq.size(); i++) {
                if (pre_sum + seq[i] >= target) return false;
            }
            for (int i = start; i < seq.size(); i++) {
                swap(seq[start], seq[i]);
                if (!mayLose(seq, start + 1, pre_sum + seq[start], target))
                    return false;
                swap(seq[start], seq[i]);
            }
            return true;
        }
    }

    int whoWin(vector<int> &seq, int start, int pre_sum, int target) {
        if (start % 2 == 1) {
            // 2nd player's turn
            for (int i = start; i < seq.size(); i++) {
                if (pre_sum + seq[i] >= target) return 2;
            }
            for (int i = start; i < seq.size(); i++) {
                swap(seq[start], seq[i]);
                if (whoWin(seq, start + 1, pre_sum + seq[start], target) == 2)
                    return 2;
                swap(seq[start], seq[i]);
            }
            return 1;
        } else {
            // 1st player's turn
            for (int i = start; i < seq.size(); i++) {
                if (pre_sum + seq[i] >= target) return 1;
            }
            for (int i = start; i < seq.size(); i++) {
                swap(seq[start], seq[i]);
                if (whoWin(seq, start + 1, pre_sum + seq[start], target) == 1)
                    return 1;
                swap(seq[start], seq[i]);
            }
            return 2;
        }
    }
};
