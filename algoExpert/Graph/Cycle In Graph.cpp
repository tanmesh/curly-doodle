#include <vector>
using namespace std;

bool cyclePresent(int node, vector<vector<int>> &edges, unordered_map<int, bool> &visited) {
	if (visited.find(node) != visited.end() && visited[node] == true) {
		return true;
	}
	visited[node] = true;

	bool cycle = false;
	for (int i = 0; i < edges[node].size(); ++i) {
		int currNode = edges[node][i];
		cycle = cycle || cyclePresent(currNode, edges, visited);
	}

	visited[node] = false;
	return cycle;
}

bool cycleInGraph(vector<vector<int>> edges) {
	unordered_map<int, bool> visited;

	for (int i = 0; i < edges.size(); ++i) {
		bool isCyclePresent = cyclePresent(i, edges, visited);
		if (isCyclePresent == true) {
			return true;
		}
	}

	return false;
}

