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
	ll n;
	cin >> n;

	if (n <= 14LL) {
		cout << "NO\n";
		return;
	}

	for (ll i = 15LL; i <= 20LL; ++i) {
		ll tmp = n - i;
		if (tmp % 14LL == 0) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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