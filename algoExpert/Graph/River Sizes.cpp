#include <vector>
using namespace std;

// O(N*M)T, O(N*M)S
int dfs(int x, int y, vector<vector<int>> &matrix, vector<vector<bool>> &visited) {
	visited[x][y] = true;

	int N = matrix.size(), M = matrix[0].size();
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};

	int size = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
			if (!visited[nx][ny] && matrix[nx][ny] == 1) {
				size += 1 + dfs(nx, ny, matrix, visited);
			}
		}
	}

	return size;
}

vector<int> riverSizes(vector<vector<int>> matrix) {
	int N = matrix.size(), M = matrix[0].size();
	vector<int> riverSize;
	vector<vector<bool>> visited(N, vector<bool> (M, false));

	int size = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			size = 0;
			if (!visited[i][j] && matrix[i][j] == 1) {
				size = 1 + dfs(i, j, matrix, visited);
				riverSize.push_back(size);
			}
		}
	}

	return riverSize;
}

