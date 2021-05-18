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

void print_(vector<int>& input, int n) {
	for (int i = 0; i < n; ++i) {
		cout << input[i] << " ";
	}
	cout << endl;
}

void merge(vector<int>& input, int l, int mid, int h) {
	vector<int> left, right;
	int i = l, j = mid + 1;
	while (i <= mid) {
		left.push_back(input[i++]);
	}
	while (j <= h) {
		right.push_back(input[j++]);
	}

	i = 0, j = 0;
	int k = l;
	while (i + l <= mid && j + mid + 1 <= h) {
		if (left[i] < right[j]) {
			input[k++] = left[i++];
		} else {
			input[k++] = right[j++];
		}
	}

	while (i + l <= mid) {
		input[k++] = left[i++];
	}

	while (j + mid + 1 <= h) {
		input[k++] = right[j++];
	}
}

void mergeSort(vector<int>& input, int l, int h) {
	if (l < h) {
		int middle = l + (h - l) / 2;
		mergeSort(input, l, middle);
		mergeSort(input, middle + 1, h);

		merge(input, l, middle, h);
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
	mergeSort(input, 0, n - 1);
	print_(input, n);
	return 0;
}