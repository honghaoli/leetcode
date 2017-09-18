class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() < 1 || num2.size() < 1) return "Empty input!";
        if (num1 == "0" || num2 == "0") return "0";
        if (num1 == "1") return num2;
        if (num2 == "1") return num1;
        
        // reverse 
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string result = "";
        for (int i = 0; i < num1.size(); i++) {
            int n1 = num1[i] - '0';
            int carry = 0;
            for (int j = 0; j < num2.size(); j++) {
                int n2 = num2[j] - '0';
                int m = n1 * n2 + carry;
                if (i + j < result.size())
                    m += result[i + j] - '0';
                int digit = m % 10;
                carry = m / 10;
                if (i + j == result.size())
                    result += digit + '0';
                else
                    result[i + j] = digit + '0';
            }
            
            if (carry != 0)
               result += carry + '0';
        }
        

        // remove trailing zeros
        
        // reverse back
        reverse(result.begin(), result.end());
        return result;
    }

};
