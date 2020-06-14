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
	int dp[100][100];
	memset(dp, 0, 100 * 100);

	stack<pair<int, int> > elementInStack;

	for (int i = 0; i < n; ++i) {
		int currElement = input[i];
		dp[currElement][i] = 1;

		if (elementInStack.empty()) {
			elementInStack.push(make_pair(currElement, i));
			continue;
		}

		int prevElement = input[i - 1];

		if (prevElement < currElement) {
			dp[currElement][i] = dp[prevElement][i - 1] + 1;
			elementInStack.push(make_pair(currElement, i ));
		} else {
			elementInStack.pop();
			while (!elementInStack.empty()) {
				pair<int, int> prevv = elementInStack.top();
				if (prevv.F < currElement) {
					elementInStack.push(make_pair(currElement, i));
					dp[currElement][i] = 1 + dp[prevv.F][prevv.S];
					break;
				}
				elementInStack.pop();
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, dp[input[i]][i]);
	}
	cout << ans << endl;
	return 0;
}