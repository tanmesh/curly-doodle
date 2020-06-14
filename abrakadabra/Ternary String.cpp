#include <bits/stdc++.h>

using namespace std;

#define all(a)          a.begin(), a.end()
#define allr(a)         a.rbegin(), a.rend()
#define F				first
#define S				second
#define pb              push_back
#define ll				long long
#define f(i, a, n)		for(int i=a; i<n; ++i)
#define find(a, b)		(find(a.begin(), a.end(), b) == a.end())
#define fast 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define watch(x) 		cout << (#x) << " is " << (x) << endl

void solve() {
	string input;
	cin >> input;
	int one = -1, two = -1, three = -1;
	int ans = INT_MAX;
	for (int i = 0; i < input.size(); ++i) {
		if (input[i] == '1') {
			one = i;
		} else if (input[i] == '2') {
			two = i;
		} else {
			three = i;
		}
		if (one >= 0 && two >= 0 && three >= 0) {
			int minn = min(one, min(two, three));
			int maxx = max(one, max(two, three));
			ans = min(ans, maxx - minn + 1);
		}
	}
	if (ans == INT_MAX) {
		ans = 0;
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