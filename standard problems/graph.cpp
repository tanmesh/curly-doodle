#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

void print(vector<int> &traversal) {
	for(auto it: traversal) {
		cout << it << " ";
	}
	cout << endl;
}

vector<vector<int>> buildGraph() {
	int N, edges;
	cout << "Enter Nodes and Edges cnt followed by Edges:\n";
	cin >> N >> edges;

	vector<vector<int>> graph(N);
	for(int i=0; i<edges; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	return graph;
}

void dfsUsingRecursion(int node, vector<int> &traversal, vector<vector<int>> &graph, unordered_map<int, bool> &visited) {
    visited[node] = true;
    traversal.push_back(node);
    for(auto child: graph[node]) {
        if(visited.find(child) == visited.end()) {
            dfsUsingRecursion(child, traversal, graph, visited);
        }
    }
}

void dfsUsingStack(int node, vector<int> &traversal, vector<vector<int>> &graph, unordered_map<int, bool> &visited) {
	stack<int> stk;
	stk.push(node);
	while(!stk.empty()) {
		node = stk.top();
		stk.pop();

		visited[node] = true;
		traversal.push_back(node);

		for(auto child: graph[node]) {
			if(visited.find(child) == visited.end()) {
				stk.push(child);
			}
		}
	}
}

void dfs(vector<vector<int>> &graph) {
	vector<int> traversal;
	unordered_map<int, bool> visited;
	
	traversal.clear();
	visited.clear();
	for(int i=0; i<graph.size(); ++i) {
		if(visited.find(i) == visited.end()) {
			dfsUsingRecursion(i, traversal, graph, visited);
		}
	}
	cout << "DFS Using Recursion : ";
	print(traversal);
	cout << endl;

	traversal.clear();
	visited.clear();
	for(int i=0; i<graph.size(); ++i) {
		if(visited.find(i) == visited.end()) {
			dfsUsingStack(i, traversal, graph, visited);
		}
	}
	cout << "DFS Using Stack : ";
	print(traversal);
	cout << endl;
}

void bfs(vector<vector<int>> &graph) {
	vector<int> traversal;
	unordered_map<int, bool> visited;

	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int node = q.front();
		q.pop();

		visited[node] = true;
		traversal.push_back(node);

		for(auto child: graph[node]) {
			if(visited.find(child) == visited.end()) {
				visited[child] = true;
				q.push(child);
			}
		}
	}
	cout << "BFS Using Queue : ";
	print(traversal);
	cout << endl;
}

int main() {
	vector<vector<int>> graph = buildGraph();

	// dfs(graph);

	bfs(graph);

	return 0;
}