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

int upperBound(vector<int>& input, int n, int key) {
	int low = 0, high = n;
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (key < input[mid]) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return low;
}

int lowerBound(vector<int>& input, int n, int key) {
	int low = 0, high = n;
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (key <= input[mid]) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return low;
}

int binarySearch(vector<int>& input, int n, int key) {
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (key == input[mid]) {
			return mid;
		} else if (key < input[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return -1;
}


int main () {
	fast
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	int key;
	cin >> key;

	cout << "lowerBound: " << lowerBound(input, n, key) << endl;
	cout << "upperBound: " << upperBound(input, n, key) << endl;
	// cout << binarySearch(input, n, key) << endl;
	return 0;
}









