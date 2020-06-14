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
	ll n, s;
	cin >> n >> s;
	vector<ll> a(n);

	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (ll i = 0; i < n; ++i) {
		a[i] = a[i] + a[i - 1];
	}

	ll i;
	for (i = 0; i < n; ++i) {
		if (a[i] >= s) {
			break;
		}
	}

	// for (ll j = i + 1; j < n; ++j) {
	// 	cout << a[j] << " " << a[i] << endl;
	// 	if ((a[j] - a[i]) >= s) {
	// 		break;
	// 	}
	// 	++ans;
	// }

	cout << i << endl;
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