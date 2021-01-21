// Solution 1: Using Binary Search, O(logN)T, O(1)S
class Solution {
public:
    int caluclateNegativeNumsInRow(vector<int> row) {
        int low = 0, high = row.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (row[mid] < 0) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return row.size() - low;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int negativeNums = 0;
        for (auto row : grid) {
            negativeNums += caluclateNegativeNumsInRow(row);
        }

        return negativeNums;
    }
};