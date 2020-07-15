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

int check(long long int mid, vector<int>& C) {
	int count = 1;
	long long int sum = 0;
	for (int i = 0; i < C.size(); i++) {
		if (sum + C[i] > mid)   {
			sum = C[i];
			count++;
			if (C[i] > mid)  {
				return INT_MAX;
			}
		}
		else {
			sum += C[i];
		}
	}
	return count;
}

int paint(int A, int B, vector<int> &C) {
	long long int low = LONG_MAX, high = 0;
	for (int i = 0; i < C.size(); i++) {
		low = min(low, (long long)C[i]);
		high += C[i];
	}
	long long int ans, mid;

	while (low <= high) {
		mid = low + (high - low) / 2;
		if (check(mid, C) <= A) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return (ans * B) % 10000003;
}

int main () {
	fast
	int a, b;
	cin >> a >> b;

	int n;
	cin >> n;
	vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	cout << paint(a, b, c) << endl;
	return 0;
}