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
	vector<int> arr(n, 0);
	set <pair <int, pair <int, int> > > q;
	q.insert(make_pair(-n, make_pair(0, n-1)));
	for(int i=0; i<n; ++i) {
		auto it = *q.begin();
		q.erase(q.begin());
		int l = it.S.F;
		int r = it.S.S;
		int mid = (l + r)/2;
		arr[mid] = i+1;
		if(l < mid) {
			q.insert(make_pair(l - mid, make_pair(l, mid - 1)));
		}
		if(mid < r) {
			q.insert(make_pair((mid + 1) - r - 1, make_pair(mid + 1, r)));
		}
		for(auto data: q) {
			cout << data.F << " " << data.S.F << " " << data.S.S << endl;
		}
	}
	for(int i=0; i<arr.size(); ++i) {
		cout << arr[i] << " ";
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