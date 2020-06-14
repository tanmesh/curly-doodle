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

int main () {
	fast
	int n;
	cin >> n;
	string input;
	cin >> input;
	vector< int> pos[26];

	for (int i = 0; i < n; ++i) {
		pos[input[i] - 'a'].push_back(i + 1);
	}

	int m;
	cin >> m;
	while (m--) {
		string inputName;
		cin >> inputName;
		vector<int> cnt(26);
		for (auto &ch : inputName) {
			++cnt[ch - 'a'];
		}

		int ans = -1;
		for (int i = 0; i < 26; ++i) {
			if (cnt[i] > 0) {
				ans = max(ans, pos[i][cnt[i] - 1]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}