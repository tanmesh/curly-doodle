using namespace std;

int findPeakLength(int i, vector<int> &array) {
	int leftHalfLength = 0, rightHalfLength = 0;

	int j = i - 1;
	while (j >= 0 && array[j] < array[j + 1]) {
		++leftHalfLength;
		--j;
	}

	j = i + 1;
	while (j < array.size() && array[j - 1] > array[j]) {
		++rightHalfLength;
		++j;
	}

	return leftHalfLength + 1 + rightHalfLength;
}

int longestPeak(vector<int> array) {
	if (array.size() <= 2) {
		return 0;
	}

	int ans = INT_MIN;
	for (int i = 1; i < array.size() - 1; ++i) {
		if (array[i - 1] < array[i] && array[i] > array[i + 1]) {
			ans = max(ans, findPeakLength(i, array));
		}
	}

	return ans == INT_MIN ? 0 : ans;
}

