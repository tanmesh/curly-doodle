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

int solve() {
	int n;
	cin >> n;
	int half = n/2;
	int left = 0, right = 0;
	left = pow(2, n);
	n--;
	while(half-- > 0) {
		right += pow(2, n);
		n--;
	}
	while(n > 0) {
		left += pow(2, n);
		n--;
	}
	cout << abs(left - right) << endl;
	return 0;
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