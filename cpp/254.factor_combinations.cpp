class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> path;       
        findNext(result, path, n, 2);
        return result;
    }

private:
    void findNext(vector<vector<int>> &result, vector<int> &path, int n, int pre) {
        for (int i = pre; i < sqrt(n + 1); i++) {
            if (n % i == 0) {
                path.push_back(i);
                path.push_back(n / i);
                result.push_back(path);
                path.pop_back();
                findNext(result, path, n / i, i);
                path.pop_back();
            }
        }
    }
};