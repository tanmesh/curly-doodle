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

int searchMatrix(vector<vector<int> > &A, int B) {
	for (int i = 0; i < A.size(); ++i) {
		if (binary_search(A[i].begin(), A[i].end(), B) == true) {
			return 1;
		}
	}
	return 0;
}

int main () {
	fast

	int n, m;
	cin >> n >> m;
	vector< vector<int> > a(n, vector<int> (m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	int b;
	cin >> b;

	cout << searchMatrix(a, b) << endl;
	return 0;
}