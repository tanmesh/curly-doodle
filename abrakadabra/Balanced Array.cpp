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
  	if((n/2) % 2 != 0) {
  		cout << "NO\n";
  		return;
  	}
  	cout << "YES\n";
  	vector<int> ans;
  	int even_cnt = 2;
  	int sum = 0;
  	for(int i=0; i<n/2; ++i) {
  		ans.push_back(even_cnt);
  		sum += even_cnt;
  		even_cnt += 2;
  	}
  	int odd_cnt = 1;
  	int i = 1;
  	while(i != n/2) {
  		ans.push_back(odd_cnt);
  		sum -= odd_cnt;
  		odd_cnt += 2;
  		++i;
  	}
  	ans.push_back(sum);
  	for(int i=0; i<n; ++i) {
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
