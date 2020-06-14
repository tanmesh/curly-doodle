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
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	int sum = 0;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	for(int i=0; i<n; ++i) {
		cin >> b[i];
	}
	sort(all(a));
	sort(allr(b));

	int ans = sum;
	for(int i=0; i<k; ++i) {
		sum = 0;
		a[i] = b[i];
		for(int i=0; i<n; ++i) {
			sum += a[i];
		}
		ans = max(ans, sum);
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