class Solution {
public:
    // straight forward implementation
    string convert(string s, int numRows) {
        int size = s.size();
        if (size <= 2 || numRows <= 1)
            return s;
        
        vector<string> strings(numRows, "");
        int period = 2 * (numRows - 1);
        for (int i = 0; i < size; i++) {
            int row = i % period;
            if (row > numRows - 1)
                row = period - row;
            strings[row].push_back(s[i]);
        }
        
        string result = "";
        for (int i = 0; i < numRows; i++) {
            result += strings[i];
        }
        return result;
    }
};







class Solution {
public:
    // directly calculate the index of the char in the new array
    string convert(string s, int numRows) {
        int size = s.size();
        if (size <= 2 || numRows == 1)
            return s;
        
        vector<int> shift(numRows, 0);      // how many chars per row;
        int period = 2 * (numRows - 1);
        int left = size % period;
        int repeat = size / period;
        for (int i = 0; i < numRows; i++) {
            if (i == 0 || i == numRows-1)
                shift[i] = repeat;
            else
                shift[i] = 2 * repeat;            
        }
        for (int i = 0; i < left; i++) {

            if (i < numRows)
                shift[i]++;
            else
                shift[period - i]++;
        }
        vector<int> counts(numRows, 0);
        for (int i = 1; i < numRows; i++) {
            counts[i] = shift[i-1] + counts[i-1];
        }
        
        string result(s);
        for (int i = 0; i < size; i++) {
            int row = i % period;
            int samerow = i / period;
            if (row != 0 && row != numRows-1)
                samerow *= 2;
            if (row > numRows-1) {
                row = period - row;
                samerow++;
            }
            int idx = counts[row] + samerow;
            result[idx] = s[i];
        }
        
        return result;
    }
};
