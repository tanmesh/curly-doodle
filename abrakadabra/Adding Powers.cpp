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
	const int N = 1e5 + 5;
	int n, k;
	cin >> n >> k;
	vector<ll> input(N);
	map<ll, ll> m;
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
		int x = input[i];
		int cur = 0;
		while (x > 0) {
			m[cur] += x % k;
			cout << m[cur] << endl;
			x /= k;
			cout << x << endl;
			cur++;
		}
		cout << endl;
	}
	int flag = 1;
	for (auto &it : m) {
		if (it.second > 1) {
			flag = 0;
		}
	}
	if (!flag) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
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