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
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	vector < vector <int> > ans;

	for (int i = 0; i < (int)pow(2, n); ++i ) {
		vector<int> a;
		for (int j = 0; j < n; ++j) {
			if (((1 << j)&i) != 0) {
				a.push_back(input[j]);
			}
		}
		ans.push_back(a);
	}

	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}