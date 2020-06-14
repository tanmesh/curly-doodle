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

int maxPower(string s) {
	int ans = 1, cnt = 1;
	for (int i = 0; i < s.size(); ++i) {
		cnt = 1;
		for (int j = i + 1; j < s.size(); ++j) {
			if (s[i] != s[j]) {
				break;
			} else {
				++cnt;
				ans = max(ans, cnt);
			}
		}
	}

	return ans;
}

int main () {
	fast
	string s;
	cin >> s;
	cout << maxPower(s) << endl;
	return 0;
}