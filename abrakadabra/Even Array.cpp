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
	int input;

	int even = 0, odd = 0;
	for (int i = 0; i < n; ++i) {
		cin >> input;
		if (i % 2 != input % 2) {
			if (i % 2 == 0) {
				++even;
			} else {
				++odd;
			}
		}
	}
	if (even == odd) {
		cout << even << endl;
	} else {
		cout << -1 << endl;
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