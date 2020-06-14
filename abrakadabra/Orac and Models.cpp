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
	int n;
	cin >> n;
	vector<int> input(n + 1);
	for (int i = 1; i < n + 1; ++i) {
		cin >> input[i];
	}
	vector< int > dp(n + 1, 1);
	int ans = -1;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + i; j <= n; j += i) {
			cout << j << " ";
			if (input[i] < input[j]) {
				dp[j] = max(dp[j], dp[i] + 1);
			}
		}
		cout << endl;
		ans = max(ans, dp[i]);
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