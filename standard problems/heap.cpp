#include <bits/stdc++.h>

using namespace std;

#define all(a)          a.begin(), a.end()
#define allr(a)         a.rbegin(), a.rend()
#define F				first
#define S				second
#define pb              push_back
#define ll				long long
#define fast 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define watch(x) 		cout << (#x) << " is " << (x) << endl

void printHeap(vector<int> input, int n) {
	for (int i = 0; i < n; ++i) {
		cout << input[i] << " ";
	}
	cout << endl;
}

void heapify(vector<int>& input, int i, int n) {
	int id = i;
	int left_child = 2 * i;
	int right_child = 2 * i + 1;

	if (left_child <= n) {
		if (input[id] < input[left_child]) {
			id = left_child;
		}
	}
	if (right_child <= n) {
		if (input[id] < input[right_child]) {
			id = right_child;
		}
	}

	if (id != i) {
		swap(input[id], input[i]);
		heapify(input, id, n);
	}
}

void buildHeap(vector<int>& input, int n) {
	for (int i = n / 2; i >= 0; --i) {
		heapify(input, i, n - 1);
	}
}

void heapSort(vector<int>& input, int n) {
	for (int i = n - 1; i > 0; --i) {
		swap(input[0], input[i]);
		heapify(input, 0, i - 1);
	}
}

int main () {
	fast
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}

	buildHeap(input, n);

	printHeap(input, n);

	heapSort(input, n);

	printHeap(input, n);
	return 0;
}