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
  	ll n, m;
  	cin >> n >> m;
  	vector<ll> a(m);
  	for(ll i=0; i<m; ++i) {
  		cin >> a[i];
  	}
  	ll prev_house = 1, ans = 0;
  	for(ll i=0; i<m; ++i) {
  		ll curr_house = a[i];
  		if(prev_house <= curr_house) {
  			ans += curr_house - prev_house;
  		} else {
  			ans += n - (prev_house - curr_house);
  		}
  		prev_house = curr_house;
  	}
  	cout << ans << endl;
	return 0;
}