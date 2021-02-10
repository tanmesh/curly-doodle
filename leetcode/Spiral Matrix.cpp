class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size();
        int left = 0, right = matrix[0].size();

        vector<int> result;
        while (left < right && top < bottom) {
            // left to right
            for (int i = left; i < right; ++i) {
                result.push_back(matrix[top][i]);
            }
            ++top;

            // top to bottom
            for (int i = top; i < bottom; ++i) {
                result.push_back(matrix[i][right - 1]);
            }
            --right;

            // this condition when there is only a row or column is left to traverse
            if (left >= right || top >= bottom) {
                break;
            }

            // right to left
            for (int i = right - 1; i > left - 1; --i) {
                result.push_back(matrix[bottom - 1][i]);
            }
            --bottom;

            // down to up
            for (int i = bottom - 1; i > top - 1; --i) {
                result.push_back(matrix[i][left]);
            }
            ++left;
        }
        return result;
    }
};