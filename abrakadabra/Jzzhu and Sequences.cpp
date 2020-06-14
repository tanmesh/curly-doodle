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
	ll x, y, n;
	ll mod = 1000000007, ans;
	cin >> x >> y >> n;
	n %= 6;
	switch (n) {
	case 1:
		ans = x;
		break;
	case 2:
		ans = y;
		break;
	case 3:
		ans = (y - x);
		break;
	case 4:
		ans = (-1) * x;
		break;
	case 5:
		ans = (-1) * y;
		break;
	case 0:
		ans = (-1) * (y - x);
		break;
	}
	cout << (ans + mod) % mod << endl;
	return 0;
}