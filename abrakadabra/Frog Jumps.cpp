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
	vector<int> arr;
	arr.push_back(0);
	for(int i=0; i<input.size(); ++i) {
		if(input[i] == 'R') {
			arr.push_back(i+1);
		}
	}
	arr.push_back(input.size()+1);
	int prv = arr[0], ans = -1;
	for(int i=1; i<arr.size(); ++i) {
		ans = max(ans, arr[i] - prv);
		prv = arr[i];
	}
	cout << ans << endl;
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