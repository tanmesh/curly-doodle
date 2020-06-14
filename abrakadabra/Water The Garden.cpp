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
	vector<int> garden(n+1, 0);
	for(int i=1; i<=k; ++i) {
		int tmp;
		cin >> tmp;
		garden[tmp] = 1;
	}
	int cnt_space = 0;
	vector<int> spaces;
	for(int i=1; i<=n; ++i) {
		if(garden[i] == 0) {
			++cnt_space;
		} else {
			spaces.push_back(cnt_space);
			cnt_space = 0;
		}
	}
	spaces.push_back(cnt_space);
	int ans = spaces[0]+1;
	ans = max(ans, spaces[spaces.size()-1]+1);
	for(int i=1; i<spaces.size()-1; ++i) {
		ans = max(ans, (spaces[i]+1)/2 + 1);
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