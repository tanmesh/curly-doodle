class Solution {
public:
    int calculateMaxHeight(vector<vector<int>>& grid) {
        int maxHeight = -1;

        for (auto row : grid) {
            for (auto cell : row) {
                maxHeight = max(maxHeight, cell);
            }
        }

        return maxHeight;
    }

    bool isValid(vector<vector<int>>& grid, int mid) {
        if (grid[0][0] > mid) {
            return false;
        }

        int n = grid.size();
        set<int> seen;
        seen.insert(0);

        int dr[4] = {1, -1, 0 , 0};
        int dc[4] = {0, 0, 1 , -1};

        stack<int> stack;
        stack.push(0);

        while (!stack.empty()) {
            int k = stack.top();
            stack.pop();

            int r = k / n, c = k % n;
            if (r == n - 1 && c == n - 1) {
                return true;
            }

            for (int i = 0; i < 4; ++i) {
                int cr = r + dr[i];
                int cc = c + dc[i];

                int ck = cr * n + cc;

                if (0 <= cr && cr < n && 0 <= cc && cc < n) {
                    if ((seen.find(ck) == seen.end()) && grid[cr][cc] <= mid) {
                        stack.push(ck);
                        seen.insert(ck);
                    }
                }
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int low = 0;
        int high = calculateMaxHeight(grid); // O(N*M)

        while (low < high) {
            int mid = low + (high - low) / 2;
            // cout << low << " " << high << " " << mid << endl;
            if (isValid(grid, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};