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
	int n, k;
	cin >> n >> k;
	int ans = n;

	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (i <= k) {
				ans = min(ans, n / i);
			}
			if (n / i <= k) {
				ans = min(ans, i);
			}
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