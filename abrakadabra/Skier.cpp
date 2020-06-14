#include <bits/stdc++.h>

using namespace std; 

#define all(a)          a.begin(), a.end()
#define allr(a)         a.rbegin(), a.rend()
#define F				first
#define S				second
#define pb              push_back
#define ll				long long
#define f(i, a, n)		for(int i=a; i<n; ++i)
// #define find(a, b)		(find(a.begin(), a.end(), b) == a.end())		
#define fast 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define watch(x) 		cout << (#x) << " is " << (x) << endl

void solve() {
	string input;
	cin >> input;
	map< pair< pair<int, int>, pair<int, int> >, bool> visited;
	int x = 0, y = 0, xx = 0, yy = 0, ans = 0;
	for(auto ch: input) {
		if(ch == 'N') {
			++y;
		}
		if(ch == 'S') {
			--y;
		}
		if(ch == 'W') {
			--x;
		}
		if(ch == 'E') {
			++x;
		}
		if(visited[make_pair(make_pair(x, y), make_pair(xx, yy))] || visited[make_pair(make_pair(xx, yy), make_pair(x, y))]) {
			ans += 1;
		} else {
			ans += 5;
			visited[make_pair(make_pair(x, y), make_pair(xx, yy))] = true;
			visited[make_pair(make_pair(xx, yy), make_pair(x, y))] = true;
		}
		xx = x;
		yy = y;
	}
	cout << ans << endl;;
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