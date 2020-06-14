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
	int n, m;
	cin >> n >> m;
	string input;
	cin >> input;
	vector<int> p(n + 1, 0), output(n + 1, 0);

	for (int i = 0; i < m; ++i) {
		int tmp;
		cin >> tmp;
		++p[tmp];
	}

	output[1] = m;
	for (int i = 2; i < n; ++i) {
		output[i] = output[i - 1] - p[i - 1];
	}

	vector<int> alph(26, 0);
	for (int i = 1; i <= n; ++i) {
		char ch = input[i - 1] - 'a';
		alph[ch] += output[i];
	}

	for (int i = 0; i < n; ++i) {
		char ch = input[i] - 'a';
		++alph[ch];
	}

	for (int i = 0; i < 26; ++i) {
		cout << alph[i] << " ";
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