class Solution {
public:
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto prerequisite : prerequisites) {
            int u = prerequisite[0];
            int v = prerequisite[1];
            graph[u].push_back(v);
        }

        return graph;
    }

    bool isCyclePresent(int node, vector<vector<int>> &graph, vector<int> &visited) {
        visited[node] = 1;

        for (auto child : graph[node]) {
            if (visited[child] == 0) {
                if (isCyclePresent(child, graph, visited)) {
                    return true;
                }
            } else if (visited[child] == 1) {
                return true;
            }
        }

        visited[node] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);

        vector<int> visited(numCourses, 0);

        for (int node = 0; node < numCourses; ++node) {
            if (visited[node] == 0) {
                if (isCyclePresent(node, graph, visited)) {
                    return false;
                }
            }
        }

        return true;
    }
};