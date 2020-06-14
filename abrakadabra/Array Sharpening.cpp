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
	vector<int> input(n);

	int prefix_end = -1, sufix_end = n;

	for(int i=0; i<n; ++i) {
		if(input[i] < i) {
			break;
		} 
		prefix_end = i;
	}
	
	for(int i=n-1; i>=0; --i) {
		if(input[i] < n-1-i) {
			break;
		}
		suffix_end = i;
	}

	if(suffix_end == prefix_end) {
		cout << "YES\n";	
	} else {
		cout << "NO\n";
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