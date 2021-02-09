class Solution {
private:
    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>> &visited) {
        visited[x][y] = true;

        int N = grid.size(), M = grid[0].size();
        int dx[4] = { -1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0};

        int area = 1;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (!visited[nx][ny] && grid[nx][ny] == 1) {
                    area += dfs(nx, ny, grid, visited);
                }
            }
        }

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();

        vector<vector<int>> visited(N, vector<int> (M, false));

        int area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    // DFS will return area of island
                    area = max(area, dfs(i, j, grid, visited));
                }
            }
        }

        return area;
    }
};