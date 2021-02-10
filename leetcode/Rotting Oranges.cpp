class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> queue;

        int freshOranges = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 2) {
                    queue.push({i, j});
                } else if (grid[i][j] == 1) {
                    ++freshOranges;
                }
            }
        }

        int minutes = 0;
        int dx[] = { -1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};

        while (!queue.empty()) {
            int size = queue.size();
            for (int j = 0; j < size; ++j) {
                pair<int, int> p = queue.front();
                queue.pop();
                int x = p.first;
                int y = p.second;

                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size()) {
                        if (grid[nx][ny] == 1) {
                            grid[nx][ny] = 2;
                            freshOranges--;
                            queue.push({nx, ny});
                        }
                    }
                }
            }

            if (!queue.empty()) { ++minutes; }
        }

        return freshOranges == 0 ? minutes : -1;
    }
};