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
	ll n;
	cin >> n;
	vector<ll> output, input(n);

	ll s = 0, x = 0;
	for (ll i = 0; i < n; ++i) {
		cin >> input[i];
		s += input[i];
		x ^= input[i];
	}
	output.push_back(x);
	output.push_back(x + s);
	cout << output.size() << endl;
	for (ll i = 0; i < output.size(); ++i) {
		cout << output[i] << " ";
	}
	cout << endl;
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