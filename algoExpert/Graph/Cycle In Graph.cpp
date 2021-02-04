// Solution 2 but more refined
#include <vector>
using namespace std;

int WHITE = 0;
int GREY = 1;
int BLACK = 2;

bool traverseAndColourNodes(int node, vector<vector<int>> &edges, vector<int> &colours) {
	colours[node] = GREY;

	auto neighbours = edges[node];
	for (auto neighbour : neighbours) {
		int neighbourColour = colours[neighbour];

		if (neighbourColour == GREY) {
			return true;
		}
		if (neighbourColour == BLACK) {
			continue;
		}

		bool containCycle = traverseAndColourNodes(neighbour, edges, colours);
		if (containCycle) {
			return true;
		}
	}

	colours[node] = BLACK;
	return false;
}

bool cycleInGraph(vector<vector<int>> edges) {
	int numberOfNodes = edges.size();
	vector<int> colours(numberOfNodes, WHITE);

	for (int node = 0; node < numberOfNodes; ++node) {
		if (colours[node] != WHITE) {
			continue;
		}

		bool containsCycle = traverseAndColourNodes(node, edges, colours);
		if (containsCycle) {
			return true;
		}
	}

	return false;
}


// // Solution 2: using colour, O(V+E)T, O(V)S
// #include <vector>
// using namespace std;

// bool cyclePresent(int i, vector<vector<int>> &edges, vector<int> &colour) {
// 	bool cycle = false;
// 	if(colour[i] == 1) {
// 		// Colour is Grey. Hence, has been visited.
// 		return true;
// 	} else if(colour[i] == 0) {
// 		// Colour is White. Hence, not visited yet
// 		colour[i] = 1;
// 		for(int j=0; j<edges[i].size(); ++j) {
// 			int nextNode = edges[i][j];
// 			cycle = cycle || cyclePresent(nextNode, edges, colour);
// 		}
// 		colour[i] = 2;
// 	}
// 	return cycle;
// }

// bool cycleInGraph(vector<vector<int>> edges) {
//   vector<int> colour(edges.size(), 0);

// 	for(int i=0; i<edges.size(); ++i) {
// 		bool isCyclePresent = cyclePresent(i, edges, colour);
// 		if(isCyclePresent == true) {
// 			return true;
// 		}
// 	}

//   return false;
// }


// // Solution 1: using DFS, O(V+E)T, O(V)S
// #include <vector>
// using namespace std;

// bool cyclePresent(int node, vector<vector<int>> &edges, unordered_map<int, bool> &visited) {
// 	if (visited.find(node) != visited.end() && visited[node] == true) {
// 		return true;
// 	}
// 	visited[node] = true;

// 	bool cycle = false;
// 	for (int i = 0; i < edges[node].size(); ++i) {
// 		int currNode = edges[node][i];
// 		cycle = cycle || cyclePresent(currNode, edges, visited);
// 	}

// 	visited[node] = false;
// 	return cycle;
// }

// bool cycleInGraph(vector<vector<int>> edges) {
// 	unordered_map<int, bool> visited;

// 	for (int i = 0; i < edges.size(); ++i) {
// 		bool isCyclePresent = cyclePresent(i, edges, visited);
// 		if (isCyclePresent == true) {
// 			return true;
// 		}
// 	}

// 	return false;
// }

