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
  	int n, m;
  	cin >> n >> m;
  	vector<int> input(n+1);
  	for(int i=1; i<=n; ++i) {
  		cin >> input[i];
  	}
  	for(int i=0; i<m; ++i) {
  		int l, r, x;
  		cin >> l >> r >> x;
  		int pos = 0;
  		for(int j=l; j<=r; ++j) {
  			if(input[x] > input[j]) {
  				++pos;
  			}
  		}
  		if(l + pos == x) {
  			cout << "Yes\n";
  		} else {
  			cout << "No\n";
  		}
  	}
	return 0;
}