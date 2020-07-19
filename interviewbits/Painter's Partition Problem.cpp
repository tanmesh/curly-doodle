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

bool p(long long int mid, vector<int>& C, int A) {
	long long int cnt = 1, sum = 0;
	for (int i = 0; i < C.size(); ++i) {
		if (sum + C[i] <= mid) {
			sum += C[i];
		} else {
			++cnt;
			sum = C[i];
		}
	}
	if (cnt <= A) {
		return true;
	}
	return false;
}

int paint(int A, int B, vector<int> &C) {
	long long int l = LONG_MIN, h = 0;
	for (int i = 0; i < C.size(); ++i) {
		l = max(l, (long long )C[i]);
		h += C[i];
	}

	while (l < h) {
		long long int mid = l + (h - l) / 2;
		if (p(mid, C, A) == true) {
			h = mid;
		} else {
			l = mid + 1;
		}
	}

	return (l * B) % 10000003;
}

int main () {
	fast
	int a, b;
	cin >> a >> b;

	int n;
	cin >> n;
	vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	cout << paint(a, b, c) << endl;
	return 0;
}