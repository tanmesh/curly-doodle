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

ll find_digit_sum(ll n) {
	ll ans = 0;
	while(n > 0) {
		ll last__digit = n%10;
		ans += last__digit;
		n /= 10;
	}
	return ans;
}

int main () {
  	fast
  	ll n;
  	cin >> n;
  	int i = n-100;
  	if(i<=0) i=1;

  	vector<ll> ans;
  	for(; i<n; ++i) {
  		ll i_digit_sum = find_digit_sum(i);
  		if(i + i_digit_sum == n) {
  			ans.push_back(i);
  		}
  	}
  	cout << ans.size() << endl;
  	for(auto i: ans) {
  		cout << i << endl;
  	}
	return 0;
}