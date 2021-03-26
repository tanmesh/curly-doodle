class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        for(int uniqueChar = 0; uniqueChar < 26; ++uniqueChar) {
            int leftPtr = 0, rightPtr = 0;
            int updatingSpace = 0;
            while(rightPtr < s.length()) {
                if(s[rightPtr] - 'A' != uniqueChar) {
                    ++updatingSpace;
                }
                while(leftPtr < s.length() && updatingSpace > k) {
                    if(s[leftPtr] - 'A' != uniqueChar) {
                        --updatingSpace;
                    }
                    ++leftPtr;
                }
                ans = max(ans, rightPtr - leftPtr + 1);
                ++rightPtr;
            }
        }
        return ans;
    }
};