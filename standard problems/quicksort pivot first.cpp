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

int partition(vector<int>& input, int l, int r) {
	int pivot = l;
	int j = pivot + 1;
	int i = j;
	while (j <= r) {
		if (input[pivot] > input[j]) {
			swap(input[i], input[j]);
			++i;
		}
		++j;
	}
	swap(input[pivot], input[i - 1]);
	return i - 1;
}

void quicksortPivotFirstElement(vector<int>& input, int l, int r) {
	if (l > r) {
		return;
	}
	int pivot = partition(input, l, r);
	quicksortPivotFirstElement(input, l, pivot - 1);
	quicksortPivotFirstElement(input, pivot + 1, r);
}

int main () {
	fast
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	print_(input, n);
	quicksortPivotFirstElement(input, 0, n - 1);
	print_(input, n);
	return 0;
}