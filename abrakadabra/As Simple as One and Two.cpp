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
	string input;
	cin >> input;
	vector<int> ans;
	for (int i = 0; i + 2 < input.size(); ++i) {
		if (input.substr(i, 3) == "one") {
			ans.push_back(i + 1);
			input[i] = '#';
		} else if (input.substr(i, 3) == "two") {
			ans.push_back(i + 3);
			input[i + 2] = '#';
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
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