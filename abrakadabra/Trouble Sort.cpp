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

void solve() {
	int n;
	cin >> n;
	vector<int> input(n), type(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> type[i];
	}

	bool sorted = true;
	int oneCnt = 0, zeroCnt = 0;

	for (int i = 1; i < n; ++i) {
		if (input[i] < input[i - 1]) {
			sorted = false;
			break;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (type[i] == 0) {
			++zeroCnt;
		} else {
			++oneCnt;
		}
	}

	if (oneCnt >= 1 && zeroCnt >= 1) {
		cout << "Yes\n";
	} else if (sorted == true) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

int main () {
	fast
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}