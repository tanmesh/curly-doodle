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

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += (n - i) * i;
		ans++;
	}

	cout << ans << endl;

	return 0;
}