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

void getLength(vector<int> a, vector<int> &length) {
	int i = 0;
	while (i < a.size()) {
		if (a[i] == 0) {
			++i;
			continue;
		}
		int j = i;
		while (j < a.size() && a[j] == 1) {
			j++;
		}

		for (int len = 1; len <= j - i; len++) {
			length[len] += j - i - len + 1;
		}

		i = j;
	}
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a(n), b(m);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	vector<int> length(n + 1), breath(m + 1);

	getLength(a, length);

	getLength(b, breath);

	int ans = 0;
	for (int i = 1; i < length.size(); i++) {
		if (k % i == 0 && k / i <= m) {
			ans += length[i] * breath[k / i];
		}
	}
	cout << ans << endl;

}

int main () {
	fast
	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}