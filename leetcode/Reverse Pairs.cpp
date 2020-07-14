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

// https://leetcode.com/problems/reverse-pairs/

void merge(vector<int>& input, int low, int mid, int high) {
	int n1 = mid - low + 1;
	int n2 = high - mid;
	vector<int> left, right;

	int i = 0, j = 0;
	while (i < n1) {
		left.push_back(input[low + i]);
		++i;
	}

	while (j < n2) {
		right.push_back(input[mid + 1 + j]);
		++j;
	}

	i = 0, j = 0;
	int k = low;
	while (i < n1 && j < n2) {
		if (left[i] < right[j]) {
			input[k++] = left[i++];
		} else {
			input[k++] = right[j++];
		}
	}

	while (i < n1) {
		input[k++] = left[i++];
	}

	while (j < n2) {
		input[k++] = right[j++];
	}
}

int mergeSort(vector<int>& input, int low, int high) {
	int reversePairs = 0;
	if (low < high) {
		int mid = low + (high - low) / 2;
		reversePairs += mergeSort(input, low, mid) + mergeSort(input, mid + 1, high);
		int j = mid + 1;
		for (int i = low; i <= mid; i++) {
			while (j <= high && input[i] > input[j] * 2LL) {
				j++;
			}
			reversePairs += j - (mid + 1);
		}

		merge(input, low, mid, high);
	}
	return reversePairs;
}

int reversePairs(vector<int>& nums) {
	return mergeSort(nums, 0, nums.size() - 1);
}

int main () {
	fast
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}

	cout << reversePairs(input) << endl;
	return 0;
}