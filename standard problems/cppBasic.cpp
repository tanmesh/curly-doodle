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

	cout << "MaxHeap -- Compared a < b : ";
	while(!pq1.empty()) {
		cout << pq1.top() << " ";
		pq1.pop();
	}
	cout << endl;

	cout << "MinHeap -- Compared a > b : ";
	while(!pq2.empty()) {
		cout << pq2.top() << " ";
		pq2.pop();
	}
	cout << endl;
}

void print(vector<int> &arr) {
	for(auto it: arr) {
		cout << it << " ";
	}
	cout << endl;
}

bool cmp(int& a, int& b) {
    return a < b;
}

void sortArray() {
	vector<int> arr = {100,2, 9,4, 3,5, -1,45};
	cout << "Before sort\n";
	print(arr);

	sort(arr.begin(), arr.end(), cmp);

	cout << "After sort\n";
	print(arr);
}

int main() {
	// minHeapVsMaxHeap();	
	sortArray();
	return 0;
}