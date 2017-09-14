class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> hash;
        return climbStairs(n, hash);
    }

    int climbStairs(int n, unordered_map<int, int> &hash) {
        if (n <= 2)
            return n;

        if (hash.count(n) > 0)
            return hash[n];

        int m = climbStairs(n - 1, hash) + climbStairs(n - 2, hash);
        hash[n] = m;
        return m;
    }
};
