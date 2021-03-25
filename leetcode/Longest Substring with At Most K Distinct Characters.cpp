class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> map;
        
        int leftPtr = 0, rightPtr = 0;
        int maxLength = 0;
        int distinct = 0;
        
        while(rightPtr < s.length()) {
            int updatedFrq = ++map[s[rightPtr]];
            
            if(updatedFrq == 1) {
                ++distinct;
            }
            
            while(leftPtr < s.length() && distinct > k) {
                updatedFrq = --map[s[leftPtr]];
                if(updatedFrq == 0) {
                    --distinct;
                }
                ++leftPtr;
            }
            maxLength = max(maxLength, rightPtr - leftPtr + 1);
            
            ++rightPtr;
        }
        
        return maxLength;
    }
};