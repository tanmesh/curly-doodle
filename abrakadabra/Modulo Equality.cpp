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
	int n, m;
	cin >> n >> m;
	unordered_map<int, int> mpA, mpB;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		++mpA[tmp];
	}

	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		++mpB[tmp];
	}

	int x = 0;
	while (true) {
		bool flag = true;
		for (auto element : mpA) {
			int key = (element.F + x) % m;
			if (mpA[element.F] != mpB[key]) {
				flag = false;
				break;
			}
		}
		cout << flag << endl;
		if (flag == true) {
			cout << x << endl;
			return 0;
		}
		++x;
	}
	return 0;
}