#ifndef DFS_H
#define DFS_H

#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

#include "helper.h"

using namespace std;

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

#endif