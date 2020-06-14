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
	string input;
	cin >> input;
	string ans;

	int n = input.size();
	int lastDigit = input[n - 1] - '0';

	for (int i = 0; i < n; ++i) {
		int digit = input[i] - '0';
		if (digit % 2 == 0 && digit < lastDigit) {
			swap(input[n - 1], input[i]);
			cout << input << endl;
			return 0;
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		int digit = input[i] - '0';
		if (digit % 2 == 0 && digit > lastDigit) {
			swap(input[n - 1], input[i]);
			cout << input << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}