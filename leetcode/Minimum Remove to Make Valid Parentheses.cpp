class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> removeIndex;
        for(int i=0; i<s.length(); ++i) {
            if(removeIndex.size() != 0 && removeIndex.top().first == '(' && s[i] == ')') {
                removeIndex.pop();
            } else if(s[i] == '(' || s[i] == ')') {
                removeIndex.push({s[i], i});
            }
        }
        
        string result = s;
        while(removeIndex.size() != 0) {
            int index = removeIndex.top().second;
            if(index == s.length() - 1) {
                result = result.substr(0, s.length() - 1);
            } else {
                result = result.substr(0, index) + result.substr(index + 1);
            }
            removeIndex.pop();
        }
        
        return result;
    }
};