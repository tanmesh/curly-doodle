#include <vector>
using namespace std;

// 0(NlogN + MlogM)T, O(1)S
vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
	sort(arrayOne.begin(), arrayOne.end()); // O(NlogN)T
	sort(arrayTwo.begin(), arrayTwo.end()); // O(MlogM)T

	pair<int, vector<int> > smallestDiff;
	smallestDiff.first = INT_MAX;
	smallestDiff.second = vector<int> {};

	int i = 0, j = 0;
	while (i < arrayOne.size() && j < arrayTwo.size()) {
		int diff = abs(arrayOne[i] - arrayTwo[j]);

		if (diff < smallestDiff.first) {
			smallestDiff.first = diff;
			smallestDiff.second = vector<int> {arrayOne[i], arrayTwo[j]};
		}
		if (arrayOne[i] < arrayTwo[j]) {
			++i;
		} else {
			++j;
		}
	}

	return smallestDiff.second;
}

