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
	double ans = 0.000000000000;
	while (n > 0) {
		ans += (1.0 / n);
		--n;
	}
	cout << ans << endl;
}

int main () {
	fast
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}