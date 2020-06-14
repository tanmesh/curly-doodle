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
	vector<int> input(n);
	set<int> distint;
	for(int i=0; i<n; ++i) {
		cin >> input[i];
		distint.insert(input[i]);
	}
	if(distint.size() > k) {
		cout << -1 << endl;
		return;
	}
	vector<int> cyclic;
	for(auto i: distint) {
		cyclic.push_back(i);
	}
	for(int i=0; i<(k-distint.size()); ++i) {
		cyclic.push_back(1);
	}

	vector<int> ans;
	int j = 0, i = 0;
	while(i < input.size()) {
		if(input[i] == cyclic[j]) {
			++i;
		}
		ans.push_back(cyclic[j]);
		j = (j+1)%(cyclic.size());
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