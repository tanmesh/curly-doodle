class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        
        int leftPtr = 0, rightPtr = 0;
        
        int maxLength = 0;
        int duplicate = 0;
        
        while(rightPtr < s.length()) {
            int updatedFrq = ++map[s[rightPtr]];
           
            if(updatedFrq == 2) {
                ++duplicate;
            }
            
            while(leftPtr < s.length() && duplicate > 0) {
                updatedFrq = --map[s[leftPtr]];
                if(updatedFrq == 1) {
                    --duplicate;
                }
                
                ++leftPtr;
            }
            maxLength = max(maxLength, rightPtr - leftPtr + 1);
            
            ++rightPtr;
        }
        
        return maxLength;
    }
};