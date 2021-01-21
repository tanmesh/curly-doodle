// Solution 1: Using Binary Search, O(logN)T, O(1)S
class Solution {
public:
    int mySqrt(int target) {
        int low = 0, high = target;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if ((long)mid * mid == target) {
                return mid;
            }
            if ((long)mid * mid < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};