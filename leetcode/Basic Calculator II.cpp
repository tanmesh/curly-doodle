class Solution {
public:
    int calculate(string s) {
        if(s.length() == 0) {
            return 0;
        }
        stack<int> stack;
        int currentNum = 0;
        char currentOperator = '+';
        
        for(int i=0; i<s.length(); ++i) {
            char currentChar = s[i];
            if(isdigit(currentChar)) {
                currentNum = currentNum*10 + (currentChar - '0');
            }
            if(!isdigit(currentChar) && currentChar != ' ' || i == s.length() - 1) {
                if(currentOperator == '-') {
                    stack.push(-currentNum);
                } else if(currentOperator == '+') {
                    stack.push(currentNum);
                } else if(currentOperator == '*') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop * currentNum);
                } else if(currentOperator == '/') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNum);
                }
                currentOperator = currentChar;
                currentNum = 0;
            }
        }
        
        int result = 0;
        while(!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        
        return result;
    }
};