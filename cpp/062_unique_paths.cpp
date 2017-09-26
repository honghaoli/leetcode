class Solution {
public:
    int uniquePaths(int m, int n) {
        return choose(n - 1, m + n - 2);
        // return fact(m + n - 2) / fact(m - 1) / fact(n - 1);
    }
    
private:
    
    
    // choose a from b
    long choose(int c, int n) {
        if (n - c < c)
            c = n - c;
        long result = 1;
        for (int i = 0; i < c; i++) {
            result *= n - i;
            result /= i + 1;
        }
        return result;
    }
    
    long fact(int n) {
        if (n == 1 || n == 0) return 1;
        return n * fact(n - 1);
    }
};
