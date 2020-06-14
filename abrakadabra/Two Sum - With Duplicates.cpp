#include <bits/stdc++.h>

using namespace std;

#define all(a)          a.begin(), a.end()
#define allr(a)         a.rbegin(), a.rend()
#define F				first
#define S				second
#define pb              push_back
#define ll				long long
#define f(i, a, n)		for(int i=a; i<n; ++i)
#define fast 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define watch(x) 		cout << (#x) << " is " << (x) << endl

set < pair<int, int> > twoSum(vector<int>& input, int target) {
	set < pair<int, int> > output;
	sort(all(input));
	int i = 0, j = input.size() - 1;
	while (i < j) {
		int sum = input[i] + input[j];
		if (sum == target) {
			output.insert(make_pair(input[i], input[j]));
			++i, --j;
		} else if (sum < target) {
			++i;
		} else {
			--j;
		}
	}
	return output;
}

int main () {
	fast
	int n, target;
	cin >> n >> target;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	set < pair<int, int> > output = twoSum(input, target);
	for (auto i : output) {
		cout << i.F << " " << i.S << endl;
	}
	return 0;
}