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
	string input;
	cin >> input;
	int n = input.size();
	int one = 0, zero = 0;
	for(char ch: input) {
		if(ch == '1') {
			++one;
		} else {
			++zero;
		}
	}
	if(one == 0 && zero != 0) {
		if(zero%2 != 0) {
			++zero;
		}
		string ans(zero, '0');
		cout << ans << endl;
	} else if(one != 0 && zero == 0) {
		if(one%2 != 0) {
			++one;
		}
		string ans(one, '1');
		cout << ans << endl;
	} else {
		string ans(2*n, '0');
		for(int i=0; i<2*n; i += 2) {
			ans[i] = '1';
		}
		cout << ans << endl;
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