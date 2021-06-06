#ifndef BFS_H
#define BFS_H

#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

#include "helper.h"

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

#endif