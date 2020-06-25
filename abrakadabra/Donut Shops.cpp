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
	ll a, b, c;
	ll pos1 = 0, pos2 = 0;

	cin >> a >> b >> c;
	if (c <= a) {
		pos1 = -1;
	}
	if (a * b <= c) {
		pos2 = -1;
	}

	if (pos1 == -1) {
		pos2 = b;
	}
	else if (pos2 == -1) {
		pos1 = 1;
	} else {
		pos1 = 1;
		pos2 = b;
	}
	cout << pos1 << " " << pos2 << endl;
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