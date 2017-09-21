class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> seq(n, 0);
        for (int i = 0; i < seq.size(); i++)
            seq[i] = i;
        
        vector<vector<int>> perm;
        unordered_set<int> hash1, hash2;
        permute(seq, 0, perm, hash1, hash2);
        
        vector<vector<string>> result;
        for (auto &v : perm)
            result.push_back(convertToString(v));
        
        return result;
    }
    
 
private:
    void permute(vector<int> &nums, int start, vector<vector<int>> &perm, unordered_set<int> &hash1, unordered_set<int> &hash2) {
        if (start >= nums.size()) {
            perm.push_back(nums);
        }
        
        for (int i = start; i < nums.size(); i++) {
            int plus = nums[i] + start;
            int minus = nums[i] - start;
            if (hash1.count(plus) > 0 || hash2.count(minus) > 0) continue;
            
            hash1.insert(plus);
            hash2.insert(minus);
            swap(nums[i], nums[start]);
            
            permute(nums, start + 1, perm, hash1, hash2);
            
            swap(nums[i], nums[start]);
            hash1.erase(plus);
            hash2.erase(minus);
        }
    }
    
    vector<string> convertToString(vector<int> &nums) {
        vector<string> result;
        for (int &i : nums) {
            string row(nums.size(), '.');
            row[i] = 'Q';
            result.push_back(row);
        }
        return result;
    }
    
    void print(vector<int> &nums) {
        for (auto &i : nums)
            cout << i;
        cout << endl;
    }
};
