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

void a() {
	cout << "Ashish" << endl;
}

void v() {
	cout << "Vivek" << endl;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector < vector < int> > matrix(n, vector<int> (m));
	for (int i = 0; i < n; ++i) {
		// vector<int> tmp(m);
		for (int j = 0; j < m; ++j) {
			// cin >> tmp[i];
			cin >> matrix[i][j];
		}
		// matrix.push_back(tmp);
	}

	int participant = 1;

	for (int i = 0; i < n; ++i) {
		vector<int> tmp(m);
		for (int j = 0; j < m; ++j) {
			if (matrix[i][j] != 0) {
				continue;
			}

			bool flag = true;
			for (int k = 0; k < m; ++k) {
				if (matrix[i][k] == 1) {
					flag = false;
					break;
				}
			}

			for (int k = 0; k < n; ++k) {
				if (matrix[k][j] == 1) {
					flag = false;
					break;
				}
			}

			if (flag == true ) {
				matrix[i][j] = 1;
				participant = (participant + 1) % 2;
			}
		}
	}
	if (participant == 0) {
		a();
	} else {
		v();
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