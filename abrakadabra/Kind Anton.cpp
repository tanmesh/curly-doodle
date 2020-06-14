// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define all(a)                      a.begin(), a.end()
#define allr(a)                      a.rbegin(), a.rend()
#define 							first
#define S							second
#define pb                          push_back
#define ll							long long
#define f(i, a, n)					for(int i=a; i<n; ++i)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std; 

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	f(i, 0, n) {
		cin >> a[i];
	}
	vector<int> b(n);
	f(i, 0, n) {
		cin >> b[i];
	}
	vector<int> present(2, 0);
	f(i, 0, n) {
		if(a[i] > b[i] && !present[0]) {
			cout << "NO\n";
			return;
		} if(a[i] < b[i] && !present[1]) {
			cout << "NO\n";
			return;
		}
		if(a[i] == -1) {
			present[0] = 1;
		}	
		if(a[i] == 1) {
			present[1] = 1;
		}
	}
	cout << "YES\n";
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