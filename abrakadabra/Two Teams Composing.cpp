// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define all(a)                      a.begin(), a.end()
#define allr(a)                     a.rbegin(), a.rend()
#define F							first
#define S							second
#define pb                          push_back
#define ll							long long
#define f(i, a, n)					for(int i=a; i<n; ++i)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std; 

void solve() {
    int n;
	cin >> n;
	map<int,int> mp;

	int a[n] = {0};
	for(int i=0;i<n;i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	set<int> s;
	for(auto i: mp) {
		s.insert(i.S);
	}
	int dis = mp.size();

	if(n == 1) {
		cout << 0 << endl;
		return;
	}

	int same= *(--s.end()) - 1;
	int ans = min(dis, same);
	ans = max(min(dis-1, same+1), ans);
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