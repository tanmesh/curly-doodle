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
	int n0, n1, n2;
	cin >> n0 >> n1 >> n2;
	string ans;
	if(n1 > 0) {
		ans += '1';
		for(int i=0; i<n2; ++i) {
			ans += '1';
		}
		ans += "0";
		n1--;
		for(int i=0; i<n0; ++i) {
			ans += '0';
		}
		for(int i=1; i<=n1; i++) {
			ans += (char)(i % 2 + '0');
		}
	} else {
		if(n0 > 0) {
			for(int i=0; i<n0+1; ++i) {
				ans += '0';
			}
		} else {
			for(int i=0; i<n2+1; ++i) {
				ans += '1';
			}
		}
	}
	cout << ans << endl;
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