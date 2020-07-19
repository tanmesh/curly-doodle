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

bool p(int mid, vector<int>& A, int B) {
	int cnt = 1, sum = 0;
	for (int i = 0; i < A.size(); ++i) {
		if (sum + A[i] <= mid) {
			sum += A[i];
		} else {
			++cnt;
			sum = A[i];
		}
	}

	if (cnt <= B) {
		return true;
	} else {
		return false;
	}
}

int books(vector<int> &A, int B) {
	if (A.size() < B) {
		return -1;
	}
	int l = INT_MIN, h = 0;
	for (int i = 0; i < A.size(); ++i) {
		l = max(l, A[i]);
	}

	int i = 0;
	while (i <= A.size() - B) {
		h += A[i];
		++i;
	}

	int j = 0, previousWindow = h;
	while (i < A.size()) {
		previousWindow = previousWindow + A[i] - A[j];
		h = max(h, previousWindow);
		++i, ++j;
	}

	while (l < h) {
		int mid = l + (h - l) / 2;
		if (p(mid, A, B) == true) {
			h = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}

int main () {
	fast
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < input.size(); ++i) {
		cin >> input[i];
	}

	int b;
	cin >> b;

	cout << books(input, b) << endl;
	return 0;
}