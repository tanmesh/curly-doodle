#include <bits/stdc++.h>

using namespace std;

#define all(a)          a.begin(), a.end()
#define allr(a)         a.rbegin(), a.rend()
#define F				first
#define S				second
#define pb              push_back
#define ll				long long
#define fast 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define watch(x) 		cout << (#x) << " is " << (x) << endl

void solve() {
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}

	sort(allr(input));

	for (int i = 0; i < n; ++i) {
		cout << input[i] << " ";
	}
	cout << endl;
}

int main () {
	fast
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}