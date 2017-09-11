class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        return say(countAndSay(n-1));
    }
    
    string say(string str) {
        int count = 0;
        char num = '0';
        string result = "";
        for (char &c : str) {
            if (c == num) {
                count++;
            } else {
                if (count > 0) {
                    result += std::to_string(count);
                    result += num;
                }
                count = 1;
            }
            num = c;
        }
        
        if (count > 0) {
           result += std::to_string(count);
           result += num;
        }
        return result;
    }
};
