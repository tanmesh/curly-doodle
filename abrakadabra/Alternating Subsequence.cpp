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
	vector<int> input(n);
	for(int i=0; i<n; ++i) {
		cin >> input[i];
	}
	int a = input[0];
	long long ans = 0;
	for(int i=1; i<n; ++i) {
		int b = input[i];
		if((a > 0 && b > 0) || (a < 0 && b < 0)) {
			a = max(a, b);
		} else {
			ans += a;
			a = b;
		}
	}
	cout << ans + a << endl;
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