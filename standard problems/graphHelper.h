#ifndef GRAPHHELPER_H
#define GRAPHHELPER_H

#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

vector<vector<int> > buildGraph() {
	int N, edges;
	cout << "Enter Nodes and Edgescnt\n";
	cin >> N >> edges;

	vector<vector<int> > graph(N);
	cout << "Enter edges\n";
	for(int i=0; i<edges; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	return graph;
}

void print(vector<int> &traversal) { 
	for(auto it: traversal) {
		cout << it << " ";
	}
	cout << endl;
}

vector<vector<vector<int>>> buildDirectedWeightedGraph() {
 	int vertex, edges;
 	cout << "Enter vertex and edges\n";
	cin >> vertex >> edges;
	
	vector<vector<vector<int>>> graph(vertex);

	cout << "Enter Node V, Node W and weight\n";
	for(int i=0; i<edges; i++) {
		int nodeV, nodeW, weight;
		cin >> nodeV >> nodeW >> weight;

		graph[nodeV].push_back({nodeW, weight});
	}

	return graph;
 }

#endif