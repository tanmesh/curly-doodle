class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stack;    
        for(int i=0; i<s.length(); ++i) {
            if(stack.size() == 0 || stack.top().first != s[i]) {
                stack.push({s[i], 1});
            } else {
                ++stack.top().second;
                if(stack.top().second == k) {
                    stack.pop();
                }
            }
        }
        
        string result = "";
        while(stack.size() != 0) {
            int rep = stack.top().second;
            while(rep-- != 0) {
                result = stack.top().first + result;
            }
            stack.pop();
        }
        return result;
    }
};