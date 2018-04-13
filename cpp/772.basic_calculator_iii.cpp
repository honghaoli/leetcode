// TEST cases
// "((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1))"
// convert to 
// 15 7 1 1 + - / 3 * 2 1 1 + + - 
// result = 5
class Solution {
public:
    int calculate(string s) {
        vector<string> tokens = convertToRPN(s);
        for (string &s : tokens) {
            cout << s << " ";
        }
        return evalRPN(tokens);
    }

private:
    bool inline is_op(char &c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    int precedence(char &c) {
        if (c == '+' || c == '-') return 1;
        else if (c == '*' || c == '/') return 2;
        printf("invalid operator %c", c);
        throw;
    }

    int calculate(int n1, int n2, char op) {
        if (op == '+') return n1 + n2;
        else if (op == '-') return n1 - n2;
        else if (op == '*') return n1 * n2;
        else if (op == '/') return n1 / n2;
        printf("invalid operator %c", op);
        throw;
    }

    vector<string> convertToRPN(string &s) {
        vector<string> token;
        stack<char> ops;
        bool is_last_digit = false;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            if (s[i] == '(') {
                ops.push(s[i]);
                is_last_digit = false;
            } else if (s[i] == ')') {
                while(ops.top() != '(') {
                    string op(1, ops.top());
                    ops.pop();
                    token.push_back(op);
                }
                ops.pop();
                is_last_digit = false;
            } else if (is_op(s[i])) {
                // operators
                while (!ops.empty() && ops.top() != '(' && precedence(ops.top()) >= precedence(s[i]) ) {
                    string op(1, ops.top());
                    ops.pop();
                    token.push_back(op);
                }
                ops.push(s[i]);
                is_last_digit = false;
            } else {
                // digits
                if (is_last_digit) {
                    token.back() += s[i];
                } else {
                    string num(1, s[i]);
                    token.push_back(num);
                }
                is_last_digit = true;
            }
        }
        //
        while (!ops.empty()) {
            string op(1, ops.top());
            ops.pop();
            token.push_back(op);
        }
        return token;
    }


    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0) return 0;
        stack<int> numbers;
        for (auto &s : tokens) {
            if (isOperator(s)) {
                if (numbers.size() < 2)
                    throw runtime_error("number size < 2");
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
        printf("invalid operator %s", op.c_str());
        throw;
    }
};
