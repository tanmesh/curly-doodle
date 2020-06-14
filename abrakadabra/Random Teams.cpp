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
	ll n, m;
	cin >> n >> m;
	ll mini = n, maxi = n;
	if (m > 1) {
		maxi = 1 + (n - m);
		mini = maxi - 1;
	}

	ll miniPair = mini * (mini - 1) / 2;
	ll maxiPair = maxi * (maxi - 1) / 2;
	// if (miniPair == 0) {
	// 	miniPair = maxiPair;
	// }
	cout << miniPair << " " << maxiPair << endl;
	return 0;
}