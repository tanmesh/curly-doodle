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
	ll n, x;
	cin >> n >> x;

	ll ans = 0;
	while (n--) {
		string sign, d;
		cin >> sign >> d;
		if (sign == "+") {
			x += stoi(d);
		} else {
			if (x - stoi(d) < 0) {
				++ans;
			} else {
				x -= stoi(d);
			}
		}
	}
	cout << x << " " << ans << endl;
	return 0;
}