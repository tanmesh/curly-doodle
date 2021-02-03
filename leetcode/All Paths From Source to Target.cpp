class Solution {
public:
    void findPaths(vector<vector<int>> &graph, vector<int> resultantPath, vector<vector<int>> &ans, int currentNode) {
        if (currentNode == graph.size() - 1) {
            resultantPath.push_back(currentNode);
            ans.push_back(resultantPath);
            return;
        }

        resultantPath.push_back(currentNode);
        for (auto it : graph[currentNode]) {
            findPaths(graph, resultantPath, ans, it);
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> resultantPath;
        findPaths(graph, resultantPath, ans, 0);
        return ans;
    }
};