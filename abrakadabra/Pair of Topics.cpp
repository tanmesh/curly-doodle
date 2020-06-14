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

int main () {
  	fast
  	int n;
  	cin >> n;
  	vector<int> a(n), b(n);
  	for(int i=0; i<n; ++i) {
  		cin >> a[i];
  	}
  	for(int i=0; i<n; ++i) {
  		cin >> b[i];
  		a[i] = a[i] - b[i];
  	}
  	sort(all(a));

  	ll ans = 0;
  	for(int i=0; i<n; ++i) {
  		if(a[i] > 0) {
  			int pos = lower_bound(all(a), -a[i]+1) - a.begin();
  			ans += i - pos;
  		}
  	}
  	cout << ans << endl;
	return 0;
}