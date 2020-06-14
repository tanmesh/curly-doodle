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

void print_(vector<int>& a) {
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main () {
	fast
	int n;
	cin >> n;
	string input(n + 1, ' ');
	int white = 0, black = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> input[i];
		if (input[i] == 'W') {
			++white;
		} else {
			++black;
		}
	}
	if (white % 2 != 0 && (n - white) % 2 != 0) {
		cout << -1 << endl;
		return 0;
	}

	char color = (black % 2 	!= 0 ? 'B' : 'W');

	watch(color);

	vector<int> index;
	for (int i = 1; i < n; ++i) {
		if (input[i] != color) {
			index.push_back(i);
			input[i] = 'B' + 'W' - input[i];
			input[i + 1] = 'B' + 'W' - input[i + 1];
		}
	}

	assert(input.back() == color);
	cout << index.size() << endl;
	print_(index);
	return 0;
}