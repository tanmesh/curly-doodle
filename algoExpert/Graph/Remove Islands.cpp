#include <vector>
using namespace std;

// O(N*M)T, O(N*M)S
void dfs(int x, int y, vector<vector<int>> &matrix, vector<vector<bool>> &visited) {
	visited[x][y] = true;
	matrix[x][y] = 2;

	int N = matrix.size(), M = matrix[0].size();
	int dx[4] = {1, 0 , -1 , 0};
	int dy[4] = {0, 1 , 0 , -1};

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
			if (!visited[nx][ny] && matrix[nx][ny] == 1) {
				dfs(nx, ny, matrix, visited);
			}
		}
	}
}


vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
	int N = matrix.size(), M = matrix[0].size();

	vector<vector<bool>> visited(N, vector<bool> (M, false));

	int row[2] = {0, N - 1};
	int col[2] = {0, M - 1};

	// 	O(2M)T
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < M; ++j) {
			int x = row[i], y = j;
			if (!visited[x][y] && matrix[x][y] == 1) {
				dfs(x, y, matrix, visited);
			}
		}
	}

	// 	O(2N)T
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < N; ++j) {
			int x = j, y = col[i];
			if (!visited[x][y] && matrix[x][y] == 1) {
				dfs(x, y, matrix, visited);
			}
		}
	}

	// 	O(N*M)T
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (matrix[i][j] == 2) {
				matrix[i][j] = 1;
			} else if (matrix[i][j] == 1) {
				matrix[i][j] = 0;
			}
		}
	}

	return matrix;
}

