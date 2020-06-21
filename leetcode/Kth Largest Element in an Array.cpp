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

// https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/

class Solution {
public:
	int partition(vector<int>& input, int l, int r) {
		int pivot = l;
		int j = pivot + 1;
		int i = j;
		while (j <= r) {
			if (input[pivot] > input[j]) {
				swap(input[i], input[j]);
				++i;
			}
			++j;
		}
		swap(input[pivot], input[i - 1]);
		return i - 1;
	}
	int findKthLargest(vector<int>& nums, int k) {
		int n = nums.size();
		k = n - k;
		int low = 0, high = n - 1;
		while (true) {
			int pivot = partition(nums, low, high);
			if (pivot == k) {
				return nums[pivot];
			} else if (pivot < k) {
				low = pivot + 1;
			} else {
				high = pivot - 1;
			}
		}
	}
};

int main () {
	fast
	Solution s = Solution();

	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	int k;
	cin >> k;
	cout << s.findKthLargest(input, k) << endl;
	return 0;
}