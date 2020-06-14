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
	vector<int> a = input;
	sort(all(a));

	int start = -1;
	for (int i = 0; i < n; ++i) {
		if (input[i] != a[i]) {
			start = i;
			break;
		}
	}

	int end = -1;
	for (int i = n - 1; i >= 0; --i) {
		if (input[i] != a[i]) {
			end = i;
			break;
		}
	}

	if (start == -1 && end == -1) {
		cout << "yes\n" << 1 << " " << 1 << endl;
		return 0;
	}

	int start1 = start, end1 = end;
	while (start1 < end1) {
		swap(a[start1], a[end1]);
		++start1;
		--end1;
	}

	for (int i = 0; i < n; ++i) {
		if (input[i] != a[i]) {
			cout << "no\n" << endl;
			return 0;
		}
	}

	cout << "yes\n" << start + 1 << " " << end + 1 << endl;

	return 0;
}