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

int main () {
	fast
	int r, c;
	cin >> r >> c;
	if (r == 1 && c == 1) {
		cout << 0 << endl;
		return 0;
	}

	if (c == 1) {
		for (int i = 1; i <= r; ++i)
			cout << i + 1	 << "\n";
		return 0;
	}

	vector< vector < ll> > matrix( r + 1, vector<ll> (c + 1, 0));

	for (int row = 1; row <= r; ++row) {
		for (int col = 1; col <= c; ++col) {
			matrix[row][col] = row * (col + r);
		}
	}

	for (int row = 1; row <= r; ++row) {
		for (int col = 1; col <= c; ++col) {
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
	return 0;
}