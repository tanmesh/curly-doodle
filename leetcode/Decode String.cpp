class Solution {
private:
    int reverse(int num) {
        int newNum = 0;
        while (num != 0) {
            newNum = newNum * 10 + num % 10;
            num /= 10;
        }
        return newNum;
    }
public:
    string decodeString(string s) {
        stack<char> stack;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ']') {
                // pop till its '['
                string decodingString = "";
                while (!stack.empty() && stack.top() != '[') {
                    decodingString = stack.top() + decodingString;
                    stack.pop();
                }

                // remove '['
                stack.pop();

                // pop till its Number
                int num = 0, base = 1;
                while (!stack.empty() && stack.top() >= '0' && stack.top() <= '9') {
                    num = num + (stack.top() - '0') * base;
                    stack.pop();
                    base *= 10;
                }

                int size = decodingString.size();
                for (int i = 0; i < num; ++i) {
                    for (int j = 0; j < size; ++j) {
                        stack.push(decodingString[j]);
                    }
                }
            } else {
                stack.push(s[i]);
            }
        }

        string result;
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }

        return result;
    }
};