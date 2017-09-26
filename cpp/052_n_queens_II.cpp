class Solution {
public:
    int totalNQueens(int n) {
        vector<int> perm(n, 0);
        for (int i = 0; i < perm.size(); i++)
            perm[i] = i;
        unordered_set<int> plus;
        unordered_set<int> minus;
        return check(perm, 0, plus, minus);
    }
    
    int check(vector<int> &perm, int start, unordered_set<int> &plus, unordered_set<int> &minus) {
        if (start >= perm.size())
            return 1;
        
        int num = 0;
        for (int i = start; i < perm.size(); i++) {
            int p = start + perm[i];
            int m = start - perm[i];
            if (plus.count(p) > 0 || minus.count(m) > 0) continue;

            swap(perm[i], perm[start]);
            plus.insert(p);
            minus.insert(m);
            
            num += check(perm, start + 1, plus, minus);
            
            swap(perm[i], perm[start]);
            plus.erase(p);
            minus.erase(m);
        }
        
        return num;
    }
};
