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
	ll ans = 0;
	ll a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (ll i = 0; i < 9; ++i) {
		ll digit = a[i];
		ll num = digit;
		while (num <= n) {
			++ans;
			num = num * 10 + digit;
		}
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