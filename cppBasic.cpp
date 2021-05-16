#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class cmp1 {
public:
	bool operator() (int &a, int &b) {
		return a < b;
	}
};

class cmp2 {
public:
	bool operator() (int &a, int &b) {
		return a > b;
	}
};

void minHeapVsMaxHeap() {
	vector<int> a = {1, 112, 13, -4, -51, 1116};
	priority_queue<int, vector<int>, cmp1> pq1;
	priority_queue<int, vector<int>, cmp2> pq2;

	for(auto it: a) {
		pq1.push(it);
		pq2.push(it);
	}

	cout << "Compared a < b : ";
	while(!pq1.empty()) {
		cout << pq1.top() << " ";
		pq1.pop();
	}
	cout << endl;

	cout << "Compared a > b : ";
	while(!pq2.empty()) {
		cout << pq2.top() << " ";
		pq2.pop();
	}
	cout << endl;
}

int main() {
	minHeapVsMaxHeap();	
	return 0;
}