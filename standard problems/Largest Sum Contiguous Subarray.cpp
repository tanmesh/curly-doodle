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

int LargestSumContiguousSubarray(vector<int>& input, int n, vector<int>& dp) {
	int ans = input[0];
	dp[0] = input[0];
	for (int i = 1; i < input.size(); ++i) {
		dp[i] = max(input[i], dp[i - 1] + input[i]);
		ans = max(ans, dp[i]);
	}
	return ans;
}

int LargestSumContiguousSubarray(vector<int>& input, int n) {
	int ans = input[0];
	int curr_max = input[0];
	for (int i = 1; i < input.size(); ++i) {
		curr_max = max(input[i], curr_max + input[i]);
		ans = max(ans, curr_max);
	}
	return ans;
}

int main () {
	fast
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	cout << LargestSumContiguousSubarray(input, n) << endl;

	vector<int> dp(n, 0);

	cout << LargestSumContiguousSubarray(input, n, dp) << endl;
	return 0;
}