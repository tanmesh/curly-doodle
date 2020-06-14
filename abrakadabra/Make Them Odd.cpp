#include <bits/stdc++.h>
#include <unordered_map>

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
	vector<int> input(n);

	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	sort(all(input));

	unordered_map<int, int> dp;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (input[i] % 2 == 0) {
			// Even number
			int div = input[i];
			// int x = log2(div);
			// if (pow(2, x) == div && dp[div] != 1) {
			// 	dp[div] = 1;
			// 	ans += x;
			// }
			while (div % 2 == 0 && dp[div] != 1) {
				dp[div] = 1;
				div /= 2;
				++ans;
			}
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