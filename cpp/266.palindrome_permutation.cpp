class Solution {
public:
    bool canPermutePalindrome(string s) {
        const int N = 128;  // assume ASCII
        vector<int> hash(N, 0);
        for (char &c : s) {
            hash[c]++;
        }
        // how many odds number
        int num = 0;
        for (int i = 0; i < N; i++) {
            if (hash[i] % 2 != 0) {
                num++;
                if (num > 1) 
                    return false;
            }
        }
        return true;
    }
};