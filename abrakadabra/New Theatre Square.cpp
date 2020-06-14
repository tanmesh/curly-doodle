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
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector< vector <int> > matrix(n, vector<int> (m, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char input;
			cin >> input;
			if (input != '.') {
				continue;
			}
			matrix[i][j] = 1;
			if (j - 1 >= 0) {
				matrix[i][j] += matrix[i][j - 1];
				matrix[i][j - 1] = 0;
			}
		}
	}

	y = min(2 * x, y);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int cells = matrix[i][j];
			if (cells % 2 == 1) {
				ans += x;
			}
			ans += (cells / 2) * y;
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