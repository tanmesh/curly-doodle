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

int upperBound(vector<int>& input, int n, int key) {
	int low = 0, high = n;
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (key < input[mid]) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return low;
}

int lowerBound(vector<int>& input, int n, int key) {
	int low = 0, high = n;
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (key <= input[mid]) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return low;
}

vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> ans;
	int left = lowerBound(nums, nums.size(), target);
	int right = upperBound(nums, nums.size(), target);

	if (left == right) {
		vector<int> a;
		a.push_back(-1);
		a.push_back(-1);
		return a;
	}
	vector<int> a;
	a.push_back(left);
	a.push_back(right - 1);
	return a;
}

void print(vector<int>& input) {
	for (int i = 0; i < input.size(); ++i) {
		cout << input[i] << " ";
	}
	cout << endl;
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

	vector<int> output = searchRange(input, target);

	print(output);
	return 0;
}