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

	int minn = INT_MAX, minnId, maxx = INT_MIN, maxxId;
	for (int i = 1; i <= n; ++i) {
		cin >> input[i];
	}

	for (int i = 1; i + 1 <= n; ++i) {
		if (abs(input[i] - input[i + 1]) > 1) {
			cout << "YES\n";
			cout << i << " " << i + 1 << endl;
			return;
		}
	}
	cout << "NO\n";
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