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
	int a, b;
	cin >> a >> b;
	int i = 1;
	int minn = min(a, b);
	int maxx = max(a, b);
	if (minn == maxx) {
		cout << 0 << endl;
	}
	while (minn < maxx) {
		if (minn + i == maxx) {
			cout << i << endl;
			return;
		}
		if (minn + i > maxx) {
			maxx += i;
		} else {
			minn += i;
		}
		++i;
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