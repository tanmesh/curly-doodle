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

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = m - 1, j = n - 1;
	int last = m + n - 1;
	while (last >= 0 && i >= 0 && j >= 0) {
		if (nums1[i] >= nums2[j]) {
			nums1[last] = nums1[i--];
		} else {
			nums1[last] = nums2[j--];
		}
		--last;
	}
	while (i >= 0) {
		nums1[last--] = nums1[i--];
	}
	while (j >= 0) {
		nums1[last--] = nums2[j--];
	}
}

int main () {
	fast
	// https://leetcode.com/problems/merge-sorted-array/
	int m, n;
	cin >> m >> n;
	vector<int> a(m + n, 0);

	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}

	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	merge(a, m, b, n);

	for (int i = 0; i < m + n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}