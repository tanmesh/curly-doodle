// Solution 1: using 2 ptr, O(leght of T)T, O(1)S
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int leftBound = s.size(), rightBound = t.size();
        int leftPtr = 0, rightPtr = 0;
        while (leftPtr < leftBound && rightPtr < rightBound) {
            if (s[leftPtr] == t[rightPtr]) {
                ++leftPtr;
            }
            ++rightPtr;
        }
        if (leftPtr == leftBound) {
            return true;
        }
        return false;
    }
};