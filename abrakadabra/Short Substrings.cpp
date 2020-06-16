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
	string input;
	cin >> input;
	string ans;
	ans += input[0];
	for (int i = 1; i + 1 < input.size(); ++i) {
		if (input[i] == input[i + 1]) {
			ans += input[i];
			++i;
		}
	}
	ans += input[input.size() - 1];
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