#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

#include "graphHelper.h"

using namespace std;

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

bool isCyclePresent(int node, vector<int>& visited, vector<vector<int>>& graph) {
    visited[node] = 1;
    for(auto child: graph[node]) {
        cout << node << " " << child << endl;
        if(visited[child] == 1) {
            return 1;
        } else if(visited[child] == 0 && isCyclePresent(child, visited, graph)) {
            return 1;   
        }
    }
    
    visited[node] = 2;
    return false;
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

class cmp {
public: 
	bool operator() (vector<int>& a, vector<int>& b) {
		return a[1] > b[1];
	}
};

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
	/*
		5 6
		3 4 2
		2 3 14
		1 4 3
		1 3 20
		1 2 6
		0 1 7
	*/

  	int nodes = edges.size();
	vector<int> shortestPath(nodes, INT_MAX);
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	
	shortestPath[start] = 0;
	pq.push({start, shortestPath[start]});
	
	while(!pq.empty()) {
		vector<int> vertex = pq.top();
		int v = vertex[0];
		int shortestPathOfV = vertex[1];
		pq.pop();
		
		for(auto child: edges[v]) {
			int w = child[0];
			int pathLength = child[1];
			
			if(shortestPath[w] > shortestPath[v] + pathLength) {
				shortestPath[w] = shortestPath[v] + pathLength;
				pq.push({w, shortestPath[w]});
			}
			
		}
	}
	for(int i=0; i<shortestPath.size(); ++i) {
		if(shortestPath[i] == INT_MAX) {
			shortestPath[i] = -1;
		}
	}
		
  	return shortestPath;
}

int main() {
	// vector<vector<int> > graph = buildGraph();

	// int nodes = graph.size();
	// vector<int> visited(nodes, 0);
	// for(int i=0; i<nodes; ++i) {
	// 	if(isCyclePresent(i, visited, graph)) {
	// 		cout << "Cycle is present\n";
	// 		break;
	// 	}
	// }
	// cout << "Cycle is not present\n";

	// dfs(graph);

	// bfs(graph);

	// vector<vector<vector<int>>> directedWeightedGraph = buildDirectedWeightedGraph();
	// vector<int> shortestPath = dijkstrasAlgorithm(0, directedWeightedGraph);
	// print(shortestPath);

	return 0;
}