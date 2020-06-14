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
	ll n, k;
	cin >> n >> k;
	ll odd = n - (k-1);
	ll even = n - 2*(k-1);
	if(odd%2 != 0 && odd > 0) {
		cout << "YES\n";
		string ans;
		for(int i=0; i<k-1; ++i) {
			ans += "1 ";
		}
		cout << ans+to_string(odd) << endl;
	} else if(even%2 == 0 && even > 0) {
		cout << "YES\n";
		string ans;
		for(int i=0; i<k-1; ++i) {
			ans += "2 ";
		}
		cout << ans+to_string(even) << endl;
	} else {
		cout << "NO\n";
	}
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