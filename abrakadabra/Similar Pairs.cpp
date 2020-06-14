#include <bits/stdc++.h>
#include <unordered_map>
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
	vector<int> odd, even;
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
		if (input[i] % 2 == 0) {
			even.push_back(input[i]);
		} else {
			odd.push_back(input[i]);
		}
	}

	int even_cnt = even.size(), odd_cnt = odd.size();

	if (odd_cnt % 2 == 0 && even_cnt % 2 == 0) {
		cout << "YES\n";
		return;
	}

	if (even_cnt != 0) {
		for (int i = 0; i < odd.size(); ++i) {
			if ((find(all(even), odd[i] + 1) != even.end()) || (find(all(even), odd[i] - 1) != even.end())) {
				--even_cnt;
				--odd_cnt;
				cout << "YES\n";
				return;
			}
		}
	}

	cout << "NO\n";
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