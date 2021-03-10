#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
  int row = 0;
	int col = matrix[0].size() - 1;
	while(row < matrix.size() && col >= 0) {
		if(matrix[row][col] == target) {
			return {row, col};
		} else if(matrix[row][col] > target) {
			col--;
		} else {
			row++;
		}
	}
  return {-1, -1};
}
 

// #include <vector>
// using namespace std;

// vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
//   for(int i=0; i<matrix.size(); ++i) {
// 		for(int j=0; j<matrix[i].size(); ++j) {
// 			if(matrix[i][j] == target) {
// 				return {i, j};
// 			}
// 		}
// 	}
//   return {-1, -1};
// }
