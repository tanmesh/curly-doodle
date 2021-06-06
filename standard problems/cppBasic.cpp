#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

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
	vector<int> arr = {100, 2, 9, 4, 3, 5, -1, 45};
	cout << "Before sort\n";
	print(arr);

	sort(arr.begin(), arr.end(), cmp);

	cout << "After sort\n";
	print(arr);
}

void unordered_setVsSet() {
	cout << "unordered_set vs set:\n";
	vector<int> arr = {-100, 2, -9, 4, 3, 5, -1, 45};

	unordered_set<int> uset;
	set<int> set;

	for(auto it: arr) {
		uset.insert(it);
		set.insert(it);
	}

	cout << "Stored in unordered_set: \n";
	for(auto it: uset) {
		cout << it << " ";
	}
	cout << endl;
	cout << "Stored in set: \n";
	for(auto it: set) {
		cout << it << " ";
	}
	cout << endl;
}

void unordered_mapVsMap() {
	cout << "unordered_map vs map:\n";
	vector<int> arr = {-100, 2, -9, 4, 3, 5, -1, 45};

	unordered_map<int, int> umap;
	map<int, int> map;

	for(auto it: arr) {
		umap[it] = 1;
		map[it] = 1;
	}

	cout << "Stored in unordered_map: \n";
	for(auto it: umap) {
		cout << it.first << " " << it.second << endl;
	}
	cout << endl;

	cout << "Stored in map: \n";
	for(auto it: map) {
		cout << it.first << " " << it.second << endl;
	}
	cout << endl;
}

void pointers() {
	int n = 10;
	cout << "value: " << n << endl;
	cout << "address: " << &n << endl;
	cout << "value stored at this address: " << *(&n) << endl;
}

void addressIsPassed(int *a, int *b) {
	*a = 21, *b = 32;
	cout << "Inside fun1: " << *a << " " << *b << endl;
}

void valueIsPassed(int &a, int &b) {
	a = 221, b = 332;
	cout << "Inside fun1: " << a << " " << b << endl;
}

int main() {
	// sortArray();

	// unordered_setVsSet();

	// unordered_mapVsMap();

	// pointers();
	int a = 2, b = 3;
	cout << "Before: " << a << " " << b << endl;
	addressIsPassed(&a, &b);
	cout << "After: " << a << " " << b << endl;

	cout << "Before: " << a << " " << b << endl;
	valueIsPassed(a, b);
	cout << "After: " << a << " " << b << endl;

	return 0;
}















