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
	vector<int> input(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> input[i];
	}
	vector<int> output(2 * n + 1);
	vector<int> check(201, 0);

	int maxx = -1;
	for (int i = 1; i <= n; i++) {
		output[2 * i - 1] = input[i];
		check[input[i]] = 1;
		maxx = max(maxx, input[i]);
	}

	for (int i = 2; i <= 2 * n; i += 2) {
		int j = output[i - 1] + 1;
		while (check[j++] != 0);
		--j;
		output[i] = j;
		check[j] = 1;
		maxx = max(maxx, j);
	}
	if (maxx <= 2 * n) {
		for (int i = 1; i < output.size(); ++i) {
			cout << output[i] << " ";
		}
	} else {
		cout << -1;
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