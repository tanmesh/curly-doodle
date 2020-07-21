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

void print(vector<int>& input) {
	for (int i = 0; i < input.size(); ++i) {
		cout << input[i] << " ";
	}
	cout << endl;
}

void dutchNationalFlagAlgorithm(vector<int>& input) {
	int low = 0, mid = 0, high = input.size() - 1;
	int i = 0;
	while (i < input.size() && mid <= high) {
		if (input[i] == 0) {
			swap(input[i], input[low]);
			++low;
			++mid;
		} else if (input[i] == 1) {
			++mid;
		} else {
			swap(input[i], input[high]);
			--high;
			--i;
		}
		++i;
	}
}

int main () {
	fast
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	dutchNationalFlagAlgorithm(input);

	print(input);
	return 0;
}