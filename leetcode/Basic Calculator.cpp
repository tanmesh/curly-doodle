class Solution {
    bool isoperator(char s) {
        return s == '+' || s == '-';
    }
    
public:
    int calculate(string s) {
        stack<int> stack;
        int num = 0;
        int sign = 1;
        int result = 0;
        
        for(int i=0; i<s.length(); ++i) {
            if(isdigit(s[i])) {
                num = num*10 + (s[i] - '0');
            } else if(isoperator(s[i])) {
                result += num * sign;
                
                num = 0;
                sign = s[i] == '-'? -1 : +1;
            } else if(s[i] == '(') {
                stack.push(result);
                stack.push(sign);
                
                sign = 1;
                num = 0;
                result = 0;
            } else if(s[i] == ')') {
                result += num*sign;
                
                int sign = stack.top();
                stack.pop();
                
                int prevResult = stack.top();
                stack.pop();
                
                result *= sign;
                result += prevResult;
                
                sign = 1;
                num = 0;
            }
        }
        result += num*sign;
        
        return result;
    }
};