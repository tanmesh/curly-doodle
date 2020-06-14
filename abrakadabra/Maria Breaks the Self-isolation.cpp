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
	vector<int> input(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> input[i];
	}

	sort(all(input));

	int has = 1, ans = 1;

	for (int i = 1; i <= n; ++i) {
		if (input[i] <= has) {
			ans = i + 1;
		}
		++has;
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