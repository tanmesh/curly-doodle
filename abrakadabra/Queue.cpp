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
	int n;
	cin >> n;
	vector<ll> st(n);
	for (int i = 0; i < n; ++i) {
		cin >> st[i];
	}
	sort(all(st));

	int notDis = 0, wt = 0;
	for (int i = 0; i < n; ++i) {
		if (st[i] >= wt) {
			++notDis;
			wt += st[i];
		}
	}
	cout << notDis << endl;
	return 0;
}