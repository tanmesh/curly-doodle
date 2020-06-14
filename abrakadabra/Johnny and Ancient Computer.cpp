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
	ll a, b;
	cin >> a >> b;

	if (a > b) {
		swap(a, b);
	}

	ll r = a;
	while (r % 2 == 0) {
		r /= 2;
	}

	ll l = b;
	while (l % 2 == 0) {
		l /= 2;
	}

	if (r != l) {
		cout << -1 << endl;
		return;
	}

	ll ans = 0;

	b /= a;
	while (b >= 8) {
		b /= 8;
		++ans;
	}

	if (b > 1) {
		++ans;
	}

	cout << ans << endl;


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