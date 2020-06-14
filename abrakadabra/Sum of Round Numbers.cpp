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
	int i = 0;
	vector<int> ans;
	while(n > 0) {
		int last_digit = n%10;
		if(last_digit != 0) {
			ans.push_back(last_digit*pow(10, i));
		}
		n /= 10;
		i++;
	}
	cout << ans.size() << endl;
	for(int i=0; i<ans.size(); ++i) {
		cout << ans[i] << " ";
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