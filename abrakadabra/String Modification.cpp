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

string mofidy(string& input, int n, int k) {
	string preffix = input.substr(k - 1, n - k + 1);
	string suffix = input.substr(0, k - 1);
	if (k % 2 == n % 2) {
		// reverse
		reverse(all(suffix));
	}
	preffix += suffix;
	return preffix;
}

void solve() {
	int n;
	cin >> n;
	string input;
	cin >> input;
	int ans = 1;
	string prev = mofidy(input, n, 1);
	string output = prev;
	// cout << 1 << " " << prev << endl;
	for (int k = 2; k <= n; ++k) {
		string preffix = mofidy(input, n, k);
		// cout << k << " " << preffix << endl;
		if (preffix < output) {
			output = preffix;
			ans = k;
		}
		prev = preffix;
	}
	cout << output << endl << ans << endl;
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