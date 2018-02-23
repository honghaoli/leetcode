class Solution {
public:
    // time O(n^2), space O(n)
    string getPermutation(int n, int k) {
        vector<int> fact = factorial(n);
        if (k > fact.back()) return "";
        
        string input;
        for (int i = 0; i < n; i++) {
            input.push_back('0' + i + 1);
        }
        
        string result;
        k--;
        for (int i = n; i > 0; i--) {
            int tier = k / fact[i - 1];
            k %= fact[i - 1];
            result.push_back(input[tier]);
            input.erase(input.begin() + tier);
        }
        return result;
    }
    

private:
    vector<int> factorial(int n) {
        vector<int> result(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            result[i] = result[i - 1] * i;
        }
        return result;
    }
};