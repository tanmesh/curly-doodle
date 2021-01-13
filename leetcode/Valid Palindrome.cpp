class Solution {
public:
    bool isPalindrome(string s) {
        int leftPtr = 0;
        int rightPtr = s.length() - 1;
        while (leftPtr <= s.length() - 1 && rightPtr >= 0) {
            while (leftPtr <= s.length() - 1 && !isalnum(s[leftPtr])) {
                ++leftPtr;
            }

            if (leftPtr == s.length()) {
                return true;
            }

            while (rightPtr >= 0 && !isalnum(s[rightPtr])) {
                --rightPtr;
            }

            if (rightPtr == -1) {
                return true;
            }

            char leftChar = tolower(s[leftPtr]);
            char rightChar = tolower(s[rightPtr]);

            if (leftChar != rightChar) {
                return false;
            }

            ++leftPtr;
            --rightPtr;
        }

        return true;
    }
};