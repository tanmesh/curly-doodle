class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size(), n = matrix[0].size();

        int low = 0, high = m * n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int midElement = matrix[mid / n][mid % n];

            if (target == midElement) {
                return true;
            }
            if (target < midElement) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }
};