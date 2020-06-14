#include <bits/stdc++.h>

using namespace std; 

#define all(a)          a.begin(), a.end()
#define allr(a)         a.rbegin(), a.rend()
#define F				first
#define S				second
#define pb              push_back
#define ll				long long
#define f(i, a, n)		for(int i=a; i<n; ++i)
#define find(a, b)		(find(a.begin(), a.end(), b) == a.end())		
#define fast 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define watch(x) 		cout << (#x) << " is " << (x) << endl

void solve() {
	ll n, m;
	cin >> n >> m;
	ll spaces = n/2;
	if(spaces == 0) {
		cout << 0 << endl;
		return;
	} else if(n == 2) {
		cout << m << endl;
		return;
	}
	ll ans = 0;
	ll value = m - (spaces - 1);
	cout << 2*value + 2*(spaces-1) << endl;
}

int main () {
  	fast
  	int t;
  	cin >> t;
  	while(t--) {
  		solve();
  	}
	return 0;
}