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
	int n;
	cin >> n;
	if(n < 4) {
		cout << -1 << endl;
		return;
	}
	for(int i=n; i>4; i--) {
		if(i%2 == 0) {
			cout << i << " ";
		}
	}
	cout << 2 << " " << 4 << " ";
	for(int i=1; i<=n; i++) {
		if(i%2 != 0) {
			cout << i << " ";
		}
	}
	cout << endl;
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