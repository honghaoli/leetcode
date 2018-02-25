class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0) return 0;
        stack<int> numbers;
        for (auto &s : tokens) {
            if (isOperator(s)) {
                if (numbers.size() < 2) throw;
                int n2 = numbers.top();
                numbers.pop();
                int n1 = numbers.top();
                numbers.pop();
                numbers.push(operation(n1, n2, s));
            } else {
                numbers.push(stoi(s));
            }
        }
        return numbers.top();
    }
    
private:
    bool inline isOperator(string &c) {
        return c == "+" || c == "-" || c == "*" || c == "/";
    }
    
    int inline operation(int &n1, int &n2, string &op) {
        if (op == "+" ) {
            return n1 + n2;
        } else if (op == "-" ) {
            return n1 - n2;
        } else if (op == "*" ) {
            return n1 * n2;
        } else if (op == "/" ) {
            return n1 / n2;
        }
        // throw error
        throw;
    }
};