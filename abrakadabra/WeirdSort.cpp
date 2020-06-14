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
	int n, m;
	cin >> n >> m;
	vector<int> input(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> input[i];
	}
	vector<int>bits(n + 1, 0);
	int pos;
	for (int i = 0; i < m; ++i) {
		cin >> pos;
		bits[pos] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j + 1 <= n; ++j) {
			if (bits[j] == 1 && input[j] > input[j + 1]) {
				int tmp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = tmp;
			}
		}
	}
	int sorted = 1;
	for (int i = 1; i + 1 <= n; ++i) {
		sorted &= (input[i] <= input[i + 1]);
	}

	if (!sorted) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
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