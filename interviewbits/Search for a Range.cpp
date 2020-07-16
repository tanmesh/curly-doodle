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

vector<int> searchRange(const vector<int> &A, int B) {
	vector<int> pos;
	if (!binary_search(all(A), B)) {
		pos.push_back(-1);
		pos.push_back(-1);
		return pos;
	}
	auto l = lower_bound(all(A), B);
	pos.push_back(l - A.begin());
	auto r = upper_bound(all(A), B);
	if (r == A.end() || *r != B) {
		--r;
	}
	pos.push_back(r - A.begin());
	return pos;
}

int main () {
	fast
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int b;
	cin >> b;

	vector<int> output = searchRange(a, b);

	print(output);
	return 0;
}