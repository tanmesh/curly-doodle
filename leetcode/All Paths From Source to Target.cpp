class Solution {
private:
    void dfs(int currentNode, int targetNode, vector<int> path, vector<vector<int>>& graph, vector<vector<int>> &result) {
        path.push_back(currentNode);

        if (currentNode == targetNode) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < graph[currentNode].size(); ++i) {
            dfs(graph[currentNode][i], targetNode, path, graph, result);
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;

        dfs(0, graph.size() - 1, vector<int> {}, graph, result);
        return result;
    }
};