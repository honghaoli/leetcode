class Solution {
public:
    // solution 1
    // From math, we know coefficient Ci = Choose i from k = k! / (i! * (k-i)!)
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 1);
        long long coeff = rowIndex;
        for (int i = 1; i < rowIndex; i++) {
            result[i] = coeff;
            coeff *= (rowIndex - i);
            coeff /= (i + 1);
        }

        return result;
    }
};
