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
	string input;
	cin >> input;

	input = " " + input;
	map < pair< int, int>, int > mp;

	mp[ {0, 0}] = 0;

	int x = 0, y = 0;
	int ans = INT_MAX;
	pair<int, int> ansPair;
	for (int i = 1; i <= n; ++i) {
		if (input[i] == 'R') {
			++x;
		} else if (input[i] == 'L') {
			--x;
		} else if (input[i] == 'U') {
			++y;
		} else if (input[i] == 'D') {
			--y;
		}

		if (mp.find({x, y}) != mp.end()) {
			int j = mp[ {x, y}] + 1;
			if (ans > i - j) {
				ans = i - j;
				ansPair = {j, i};
			}
		}

		mp[ {x, y}] = i;
	}
	if (ans == INT_MAX) {
		cout << "-1" << endl;
	} else {
		cout << ansPair.F << " " << ansPair.S << endl;
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