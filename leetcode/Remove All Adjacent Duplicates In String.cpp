class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";
    
        for(auto ch: s) {
            if(result.length() != 0 && result[result.length() - 1] == ch) {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
        }
        return result;
    }
};

// class Solution {
// public:
//     string removeDuplicates(string s) {
//         stack<char> stack;
//         stack.push(s[0]);
        
//         for(int i=1; i<s.length(); ++i) {
//             if(!stack.empty() && stack.top() == s[i]) {
//                 stack.pop();
//             } else {
//                 stack.push(s[i]);
//             }
//         }
        
//         string result = "";
//         while(!stack.empty()) {
//             result = stack.top() + result;
//             stack.pop();
//         }
        
//         return result;
//     }
// };