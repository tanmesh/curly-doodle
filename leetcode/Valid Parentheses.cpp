class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(auto ch: s) {
            if(ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            } else if(stack.empty()) {
                return false;
            } else {
                if(ch == ')' && stack.top() != '(') {
                    return false;
                }
                if(ch == '}' && stack.top() != '{') {
                    return false;
                }
                if(ch == ']' && stack.top() != '[') {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.empty();
    }
};