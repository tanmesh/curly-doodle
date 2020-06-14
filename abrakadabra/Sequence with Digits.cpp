#include <bits/stdc++.h>

using namespace std;

#define all(a)          a.begin(), a.end()
#define allr(a)         a.rbegin(), a.rend()
#define F				first
#define S				second
#define pb              push_back
#define ll				long long
#define f(i, a, n)		for(int i=a; i<n; ++i)
#define find(a, b)		(find(a.begin(), a.end(), b) == a.end())
#define fast 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define watch(x) 		cout << (#x) << " is " << (x) << endl

ll minDigit(ll n) {
	ll ans = INT_MAX;
	while (n > 0) {
		ans = min(ans, n % 10);
		n /= 10;
	}
	return ans;
}

ll maxDigit(ll n) {
	ll ans = 0;
	while (n > 0) {
		ans = max(ans, n % 10);
		n /= 10;
	}
	return ans;
}

void solve() {
	ll a, k;
	cin >> a >> k;
	if (k == 1) {
		cout << a << endl;
		return;
	}
	for (ll i = 1; i < k; ++i) {
		ll prod = minDigit(a) * maxDigit(a);
		if (prod == 0) {
			cout << a << endl;
			return;
		}
		a = a + prod;
	}
	cout << a << endl;
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