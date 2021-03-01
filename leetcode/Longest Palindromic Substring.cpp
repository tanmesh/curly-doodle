class Solution {
    vector<int> getPalindromLength(string s, int leftPtr, int rightPtr) {
        while(leftPtr >= 0 && rightPtr < s.length() && s[leftPtr] == s[rightPtr]) {
            --leftPtr;
            ++rightPtr;
        }
        
        return {leftPtr+1, rightPtr};
    }
public:
    string longestPalindrome(string s) {
        vector<int> longest = {0, 1};
        for(int i=1; i<s.length(); ++i) {
            vector<int> oddLength = getPalindromLength(s, i-1, i);
            vector<int> evenLength = getPalindromLength(s, i-1, i+1);
            
            vector<int> currentLongest = oddLength[1] - oddLength[0] > evenLength[1] - evenLength[0] ? oddLength : evenLength;
            
            longest = currentLongest[1] - currentLongest[0] > longest[1] - longest[0] ? currentLongest : longest;
        }
        
        return s.substr(longest[0], longest[1] - longest[0]);
    }
};