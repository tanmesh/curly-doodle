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
  	ll n;
  	cin >> n;
  	ll volume = 0;
  	for(int i=0; i<n; ++i) {
  		ll tmp;
  		cin >> tmp;
  		volume += tmp;
  	}
  	ll can1 = -1, can2 = -1;
  	for(int i=0; i<n; i++) {
  		ll a;
  		cin >> a;
  		if(i%2 == 0) {
  			can1 = max(can1, a);	
  		} else {
  			can2 = max(can2, a);
  		}
  	}
  	// cout << can1 << " " << can2 << endl;
  	if(volume <= can2+can1) {
  		cout << "YES\n";
  	} else {
  		cout << "NO\n";
  	}
	return 0;
}