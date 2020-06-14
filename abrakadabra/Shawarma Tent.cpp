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
	int n, sx, sy;
	cin >> n >> sx >> sy;
	map < pair <int, int>, int > possibleAns;
	possibleAns[ make_pair(sx - 1, sy)] = 0;
	possibleAns[ make_pair(sx + 1, sy)] = 0;
	possibleAns[ make_pair(sx, sy - 1)] = 0;
	possibleAns[ make_pair(sx, sy + 1)] = 0;

	int ax, ay;
	pair<int, int> ansPair;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> ax >> ay;
		for (auto& element : possibleAns) {
			int bx = element.F.F;
			int by = element.F.S;
			if (min(sx, ax) <= bx && bx <= max(sx, ax) && min(sy, ay) <= by && by <= max(sy, ay)) {
				element.S++;
				if (element.S > ans) {
					ansPair = element.F;
					ans = element.S;
				}
			}
		}
	}
	cout << ans << endl;
	cout << ansPair.F << " " << ansPair.S << endl;
	return 0;
}