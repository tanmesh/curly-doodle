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
	int N, X;
	cin >> N >> X;
	int even = 0, odd = 0;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		if (a % 2 == 0)
			even++;
		else
			odd++;
	}

	if (odd > 0 && odd - (odd % 2 == 0) + even >= X && (even > 0 || X % 2 != 0))
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';
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