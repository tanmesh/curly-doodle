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

int main() {
	int n, s;
	cin >> n >> s;

	if (2 * n <= s) {
		cout << "YES\n";
		for (int i = 0; i < n - 1; i++) {
			cout << 2 << ' ';
			s -= 2;
		}
		cout << s << '\n' << 1;
	} else {
		cout << "NO";
	}
	return 0;
}