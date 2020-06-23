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

int getI(string& input) {
	int n = input.size();
	int i = 0;
	while (i + 1 < n) {
		if (input[i] == '1' && input[i + 1] == '0') {
			break;
		}
		++i;
	}
	return i;
}

string modify(string& input, int i, int sign) {
	string ans;
	ans = input.substr(0, i) + char(sign + '0') + input.substr(i + 2);
	return ans;
}

void solve() {
	int n;
	cin >> n;
	string input;
	cin >> input;

	string ans = input;
	int i, lastI;
	int sign = -1;
	while (true) {
		i = getI(ans);

		bool one = false;
		for (int j = 0; j < i; ++j) {
			if (ans[j] == '1') {
				one = true;
				break;
			}
		}
		sign = 0;
		if (one != true) { sign = 1; }

		if (i == ans.size() - 1) { break; }
		ans = modify(ans, i, sign);
		lastI = i;
		// cout << ans << endl;
	}

	if (ans.size() != n) {
		string ans2 = ans;
		if (ans2[lastI] == '1') {
			ans2[lastI] = '0';
		} else {
			ans2[lastI] = '1';
		}
		cout << min(ans, ans2) << endl;
	} else {
		cout << ans << endl;
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