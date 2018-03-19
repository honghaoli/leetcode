// The first solution will Time-Limit-Exceeded!!!
// The reason is:
// This problem is not the same like N-queen. The absolutely order in the sequence does not matter.
// The only information is which numbers did one player choose, not the order of those choices.
// So we don't need to go through all the sequences.
// and the solution is wrong!!!!
// test for example: (10, 26) or (20, 81)

// class Solution {
// public:
//     bool canIWin(int maxChoosableInteger, int desiredTotal) {
//         int &n = desiredTotal;
//         int &m = maxChoosableInteger;
//         if (n <= m) return true;

//         vector<int> seq(m, 0);
//         for (int i = 0; i < m; i++)
//             seq[i] = i + 1;

//         if (!mayLose(seq, 0, 0, n))
//             return true;
//         else   
//             return false;
//     }

// private:
//     bool mayLose(vector<int> &seq, int start, int pre_sum, int target) {
//         if (start % 2 == 1) {
//             // 2nd player's turn
//             //if (pre_sum >= target) return false;
//             for (int i = start; i < seq.size(); i++) {
//                 if (pre_sum + seq[i] >= target) return true;
//             }
//             for (int i = start; i < seq.size(); i++) {
//                 swap(seq[start], seq[i]);
//                 if (mayLose(seq, start + 1, pre_sum + seq[start], target))
//                     return true;
//                 swap(seq[start], seq[i]);
//             }
//             return false;
//         } else {
//             // 1st player's turn
//             //if (pre_sum >= target) return true;
//             for (int i = start; i < seq.size(); i++) {
//                 if (pre_sum + seq[i] >= target) return false;
//             }
//             for (int i = start; i < seq.size(); i++) {
//                 swap(seq[start], seq[i]);
//                 if (!mayLose(seq, start + 1, pre_sum + seq[start], target))
//                     return false;
//                 swap(seq[start], seq[i]);
//             }
//             return true;
//         }
//     }
// };



// solution 2:
// use a sequence of 010101010 to represent which number is chosen, and which is not.
// store the info of each sequence result into a hashmap
// so it's better to use an integer as the sequence since the num <= 20
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        N = desiredTotal;
        M = maxChoosableInteger;
        if (N <= M) return true;
        if (N > M * (M + 1) / 2) return false;

        int seq = 0;
        unordered_map<int, bool> hash;

        return willWin(seq, 0, hash);
    }

private:
    int N, M;

    bool getBit(int &seq, int i) {
        return seq & (1 << i);
    }

    void setBit(int &seq, int i, bool b) {
        if (b)
            seq |= (1 << i);
        else
            seq &= ~(1 << i);
    }

    bool willWin(int seq, int pre_sum, unordered_map<int, bool> &hash) {
        if (pre_sum >= N) return false;
        if (hash.count(seq) > 0) return hash[seq];

        for (int i = 1; i <= M; i++) {
            if (getBit(seq, i)) continue;
            setBit(seq, i, true);
            if (!willWin(seq, pre_sum + i, hash)) {
                setBit(seq, i, false);      // very important!
                hash[seq] = true;
                return true;
            }
            setBit(seq, i, false);
        }
        hash[seq] = false;
        return false;
    }
};