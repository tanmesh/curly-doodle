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

int costToPallin(string input) {
	int cost = 0, n = input.size();
	for (int i = 0; i < n / 2; ++i) {
		if (input[i] != input[n - 1 - i]) {
			++cost;
		}
	}
	return cost;
}

void solve() {
	int n, k;
	cin >> n >> k;
	string input, requiredString;
	cin >> input;
	int minn = INT_MAX;
	vector<string> b;
	for (int i = 0; i < n; i += k) {
		string a = input.substr(i, k);
		cout << a << endl;
		b.push_back(a);
		int cost = costToPallin(a);
		if (minn > cost) {
			minn = cost;
			requiredString = a;
		}
	}
	cout << requiredString << endl;
	int m = requiredString.size();
	for (int i = 0; i < m / 2; ++i) {
		requiredString[i] = requiredString[m - 1 - i];
	}
	int ans = minn;

	for (int i = 0; i < b.size(); ++i) {
		for (int j = 0; j < (b[i]).size(); ++j) {

		}
	}
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