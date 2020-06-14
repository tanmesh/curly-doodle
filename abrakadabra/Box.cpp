
#include <bits/stdc++.h>
#include <unordered_set>

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
	vector <int> q(n), a(n);
	for (int &i : q) {
		cin >> i;
	}

	vector <bool> used(n);
	a[0] = q[0];
	used[q[0] - 1] = true;
	for (int i = 1; i < n; i++) {
		if (q[i] <= i) {
			cout << "-1\n";
			return;
		}
		if (q[i - 1] < q[i]) {
			a[i] = q[i];
			used[q[i] - 1] = true;
		}
	}

	int it = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			while (used[it]) {
				it++;
			}
			a[i] = it + 1;
			used[it] = true;
		}
	}

	for (int i : a) {
		cout << i << ' ';
	}
	cout << '\n';
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