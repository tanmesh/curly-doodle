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

// void solve() {
// 	int n, k;
// 	cin >> n >> k;
// 	string input;
// 	cin >> input;

// 	k++;
// 	vector<int> ones;
// 	for (int i = 0; i < n; ++i) {
// 		if (input[i] == '1') {
// 			ones.push_back(i);
// 		}
// 	}

// 	int ans = 0;

// 	// No ones
// 	if (ones.size() == 0) {
// 		for (int i = 0; i < n; i += k) {
// 			++ans;
// 		}
// 		cout << ans << endl;
// 		return;
// 	}

// 	// Single one
// 	if (ones.size() == 1) {
// 		for (int i = ones[0] + k; i < n; i += k) {
// 			++ans;
// 		}
// 		for (int i = ones[0] - k; i >= 0; i -= k) {
// 			++ans;
// 		}
// 		cout << ans << endl;
// 		return;
// 	}

// 	// Multiple
// 	for (int i = 0; i + 1 < ones.size(); ++i) {
// 		int a = ones[i] + k;
// 		int b = ones[i + 1] - k;

// 		while (a <= b) {
// 			if (a != b) {
// 				ans = ans + 2;
// 			} else {
// 				++ans;
// 			}
// 			a += k;
// 			b -= k;
// 		}
// 	}

// 	string tmp;
// 	for (int i = ones[ones.size() - 1]; i < n; ++i) {
// 		tmp += input[i];
// 	}
// 	for (int i = 0; i <= ones[0]; ++i) {
// 		tmp += input[i];
// 	}

// 	int a = k;
// 	int b = tmp.size() - 1 - k;

// 	while (a <= b) {
// 		if (a != b) {
// 			ans = ans + 2;
// 		} else {
// 			++ans;
// 		}
// 		a += k;
// 		b -= k;
// 	}

// 	cout << ans << endl;
// }

void solve() {
	int n, k;
	string input;
	cin >> n >> k >> input;

	int prevOne;
	vector<int> nextOne(n + 1);

	string org = input;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (input[i] == '1') {
			++cnt;
		}
	}

	if (cnt == 0) {
		input[0] = '1';
	}

	int index = 99999999;
	for (int i = n - 1; i >= 0; i--) {
		if (input[i] == '1') {
			index = i;
		}
		nextOne[i] = index;
	}

	int i = 0;
	while (i < n && input[i] == '0') {
		i++;
	}

	if (k < i) {
		input[0] = '1';
	}

	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (flag == true && input[i] == '1') {
			prevOne = i;
			flag = false;
		}
		else {
			if (input[i] == '1') {
				prevOne = i;
			} else if (i - prevOne > k && nextOne[i] - i > k) {
				input[i] = '1';
				prevOne = i;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (input[i] != org[i]) {
			ans++;
		}
	}
	cout << ans << endl;
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