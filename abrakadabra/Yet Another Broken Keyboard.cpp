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

int main () {
	fast
	ll n, k;
	cin >> n >> k;
	string input(n, ' ');
	cin >> input;

	vector<char> keys(k, ' ');
	for (ll i = 0; i < k; ++i) {
		cin >> keys[i];
	}

	ll ans = 0;
	ll cnt = 0;
	for (ll i = 0; i < n; ++i) {
		if (find(all(keys), input[i]) == keys.end()) {
			// not present
			ans += (cnt * (cnt + 1)) / 2;
			cnt = 0;
		} else {
			++cnt;
		}
	}
	ans += (cnt * (cnt + 1)) / 2;
	cout << ans << endl;
	return 0;
}