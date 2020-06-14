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

bool check(int n, vector<int>& input, vector<bool>& visited, int i) {
	for (int j = 0; j < n; ++j) {
		int xor_ = input[j] ^ i;
		if (visited[xor_] == false) {
			return false;
		}
	}
	return true;
}

void solve() {
	int n;
	cin >> n;

	int limit = 1024;
	vector<int> input(limit + 1);
	vector<bool> visited(limit + 1, false);

	for (int i = 0; i < n; ++i) {
		cin >> input[i];
		visited[input[i]] = true;
	}

	int i = 1;
	while (i < limit) {
		if (check(n, input, visited, i) == true) {
			cout << i << endl;
			return;
		}
		++i;
	}
	cout << -1 << endl;
	return;
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