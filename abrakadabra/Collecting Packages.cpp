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
	vector<pair <int, int> > input;
	for (int i = 0; i < n; ++i) {
		int r, u;
		cin >> r >> u;
		input.push_back({r, u});
	}

	sort(all(input));

	string ans;

	int r = 0, u = 0, delU, delR;
	for (int i = 0; i < n; ++i) {
		delR = input[i].F - r;
		delU = input[i].S - u;
		if (delU < 0 || delR < 0) {
			cout << "NO\n";
			return;
		}
		while (delR-- > 0) {
			ans += 'R';
		}
		while (delU-- > 0) {
			ans += 'U';
		}
		r = input[i].F;
		u = input[i].S;
	}
	cout << "YES" << endl << ans << endl;
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