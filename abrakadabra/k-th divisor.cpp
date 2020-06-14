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
  	int n, k;
  	cin >> n >> k;
  	vector<ll> ans;
  	for(int i=1; i<=sqrt(n); ++i) {
  		if(n%i == 0) {
  			ans.push_back(i);
  		}
  	}
  	int sz = ans.size();
  	for(int i=0; i<sz; ++i) {
  		if(ans[i] != 1) {
  			int tmp = n/ans[i];
  			ans.push_back(tmp);
  		}
  	}
  	cout << ans.size() << " " << k << endl;
  	// if(ans.size() < k) {
  	// 	cout << -1 << endl;
  	// 	return 0;
  	// }
  	sort(all(ans));
  	cout << ans[k-1] << endl;
	return 0;
}