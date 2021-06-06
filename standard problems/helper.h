#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

int getN(string s) {
	cout << "Enter " << s << ":\n";
	int N;
	cin >> N;
	return N;
}

vector<int> getArray(int N) {
	vector<int> input(N);
	cout << "Enter array elements:\n";
	for (int i = 0; i < N; ++i) {
		cin >> input[i];
	}
	return input;
}

void print(vector<int> &traversal) {
	for(auto it: traversal) {
		cout << it << " ";
	}
	cout << endl;
}

#endif