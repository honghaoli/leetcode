// After some thinking, given a subsequence of consecutive '+', the result should be know.
// so if ther are multiple consecutive '+' subsequence, the result would only depend on each of them separately
// Actually this theory is called Nim Game.
// so result of whole string = XOR(each separate segment)
// ref:
// https://mp.weixin.qq.com/s?__biz=MzA5MzE4MjgyMw==&mid=401839317&idx=1&sn=0660926cc1e5edab1b92aa8160fa93e6&mpshare=1&scene=1&srcid=0317pF4DWnYIJx6ovcwjNrkL&key=7e3acfcaa22ffc51e9c4b44ccdb150a1e639d069dbe22c7b291946b5d1ef2080e57222b5f9b86d67bda0640357b8832404515c0c11249fe339f07ca14ec72558cfcd8e20332f3c829fcc81b1f7fda41c&ascene=0&uin=MTUyMzg3NjAwMA%253D%253D&devicetype=iMac+MacBookAir7%252C1+OSX+OSX+10.12.3+build(16D32)&version=12020010&nettype=WIFI&fontScale=100&pass_ticket=0AiIToHJN8yqpuqRAsA5PaaQMJr8KtvlnZ2EqkX0zx%252BEZweRvHKyF%252ByjmycpUbVn
// https://www.topcoder.com/community/data-science/data-science-tutorials/algorithm-games/
// https://leetcode.com/problems/flip-game-ii/discuss/73954/Theory-matters-from-Backtracking(128ms)-to-DP-(0ms)
// https://www.geeksforgeeks.org/variation-nim-game/
// https://en.wikipedia.org/wiki/Sprague%E2%80%93Grundy_theorem
// https://en.wikipedia.org/wiki/Grundy%27s_game
class Solution {
public:
    bool canWin(string s) {
        int n = s.size();
        if (n <= 1) return false;
        dp = vector<int>(n + 1, -1);    // dp[i], grundy number with i '+'s
        int result = 0;
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '+') {
                num++;
            } else {
                result ^= grundy(num);
                num = 0;
            }
        }
        // remaining num
        result ^= grundy(num);
        return result != 0;
    }

private:
    vector<int> dp;

    // grundy number with k consecutive '+' 
    int grundy(int k) {
        if (dp[k] >= 0) return dp[k];
        unordered_set<int> gsub;        // grundy number of all the sub games.
        for (int i = 0; i <= k - 2 - i; i++) {
            gsub.insert( grundy(i) ^ grundy(k - 2 - i) );    // with two '-' flipped, 
        }
        dp[k] = firstMissingNumber(gsub);
        return dp[k];
    }

    int firstMissingNumber(unordered_set<int> &gsub) {
        for (int i = 0; i < gsub.size(); i++) {
            if (gsub.count(i) == 0) return i;
        }
        return gsub.size();
    }
};






// // DP with recursively search
// class Solution {
// public:
//     bool canWin(string s) {
//         return !willLose(s);
//     }

// private:
//     unordered_map<string, bool> dp;

//     bool willLose(string &s) {
//         if (dp.count(s) != 0) return dp[s];
//         for (int i = 1; i < s.size(); i++) {
//             if (s[i] == '+' && s[i - 1] == '+') {
//                 string tmp = s;
//                 tmp[i] = '-';
//                 tmp[i - 1] = '-';
//                 if (willLose(tmp)) {
//                     dp[s] = false;
//                     return false;
//                 }
//             }
//         }
//         dp[s] = true;
//         return true;
//     }
// };