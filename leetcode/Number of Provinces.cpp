class Solution {
private:
    void dfs(int currNode, vector<vector<int>>& isConnected, vector<bool> &visited) {
        visited[currNode] = true;

        for (int i = 0; i < isConnected[currNode].size(); ++i) {
            if (!visited[i] && isConnected[currNode][i] == 1) {
                dfs(i, isConnected, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size());

        int provinces = 0;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (!visited[i]) {
                ++provinces;
                dfs(i, isConnected, visited);
            }
        }

        return provinces;
    }
};