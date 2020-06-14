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
	int n, k;
	cin >> n >> k;
	int b1_index = n-2, b2_index = n-1;
	for(int i=1; i<k; ++i) {
		--b1_index;
		for(b2_index = n-1; b1_index != b2_index - 1; --b2_index) {
			if(++i == k) {
				break;
			}
		}
	}
	vector<char> ans(n, 'a');
	ans[b1_index] = 'b';
	ans[b2_index] = 'b';
	for(int i=0; i<ans.size(); ++i) {
		cout << ans[i];
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