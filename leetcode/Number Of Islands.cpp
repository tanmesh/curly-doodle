class Solution {
private:
    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>> &visited) {
        visited[x][y] = true;

        int N = grid.size(), M = grid[0].size();
        int dx[4] = { -1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0};

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (!visited[nx][ny] && grid[nx][ny] == '1') {
                    dfs(nx, ny, grid, visited);
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));

        int size = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, visited);
                    size++;
                }
            }
        }

        return size;
    }
};