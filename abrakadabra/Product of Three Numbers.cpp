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
	int n;
	cin >> n;

	int a, b, c;
	set<int> used;
	for (a = 2; a * a < n; ++a) {
		if (n % a == 0) {
			used.insert(a);
			n /= a;
			break;
		}
	}

	for (b = 2; b * b < n; ++b) {
		if (n % b == 0 && b != a) {
			used.insert(b);
			n /= b;
			break;
		}
	}

	c = n;

	if (int(used.size()) < 2 || used.count(n) || n == 1) {
		cout << "NO\n";
	} else {
		cout << "YES\n" << a  << " " << b << " " << c << endl;
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