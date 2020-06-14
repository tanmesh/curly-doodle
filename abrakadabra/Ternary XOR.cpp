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
	vector<int> input(n), a(n, 0), b(n, 0);
	for(int i=0; i<n; ++i) {
		char ch;
		cin >> ch;
		ch = ch - '0';
		input[i] = ch;
		if(ch != 0) {
			a[i] = ch - 1;
		}
	}

	for(int i=0; i<n; ++i) {
		cout << a[i];
	}
	cout << endl;
	
	for(int i=0; i<n; ++i) {
		b[i] = (input[i] - a[i])%3;
		cout << b[i];
	}
	cout << endl;
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