// count all cows first, then bulls
// then cows = cows - bulls
class Solution {
public:
    string getHint(string secret, string guess) {
        const int kN = 10;
        vector<int> freq1(kN, 0), freq2(kN, 0);

        int bulls = 0;
        for (int i = 0; i < guess.size(); ++i) {
            if (secret[i] == guess[i])
                ++bulls;
            ++freq1[secret[i] - '0'];
            ++freq2[guess[i] - '0'];
        }

        int cows = 0;
        for (int i = 0; i < kN; ++i) {
            cows += min(freq1[i], freq2[i]);
        }

        cows -= bulls;
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
