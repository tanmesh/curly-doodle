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

int search(const vector<int> &nums, int target) {
	int start = 0, end = nums.size() - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] >= nums[start]) {
			if (target >= nums[start] && target < nums[mid]) end = mid - 1;
			else start = mid + 1;
		}
		else {
			if (target <= nums[end] && target > nums[mid]) start = mid + 1;
			else end = mid - 1;
		}
	}
	return -1;
}

int main () {
	fast
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}

	int target;
	cin >> target;

	cout << search(input, target) << endl;
	return 0;
}