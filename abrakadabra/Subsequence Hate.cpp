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
	string s;
	cin >> s;
	int suf0 = 0, suf1 = 0;
	for (auto &it : s) {
		suf0 += (it == '0');
		suf1 += (it == '1');
	}
	int ans = min(suf0, suf1); //Make whole string 0/1
	int pref0 = 0, pref1 = 0;
	for (auto &it : s) {
		pref0 += (it == '0'), suf0 -= (it == '0');
		pref1 += (it == '1'), suf1 -= (it == '1');
		//Cost of making string 0*1*
		ans = min(ans, pref1 + suf0);
		//Cost of making string 1*0*
		ans = min(ans, pref0 + suf1);
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