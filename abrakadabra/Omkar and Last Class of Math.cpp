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
	int maxx = 1;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			maxx = max(maxx, max(i, n / i));
		}
	}
	printf("%d %d\n", maxx, n - maxx);
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