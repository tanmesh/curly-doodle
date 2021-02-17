#include <vector>
using namespace std;

void merge(vector<int> &array, int l, int mid, int h) {
	vector<int> leftSide, rightSide;
	int i = l;
	while (i <= mid) {
		leftSide.push_back(array[i++]);
	}
	i = mid + 1;
	while (i <= h) {
		rightSide.push_back(array[i++]);
	}

	int rightPtr = 0, leftPtr = 0;
	int arrayPtr = l;

	while (leftPtr < leftSide.size() && rightPtr < rightSide.size()) {
		if (leftSide[leftPtr] <= rightSide[rightPtr]) {
			array[arrayPtr] = leftSide[leftPtr];
			leftPtr++;
		} else {
			array[arrayPtr] = rightSide[rightPtr];
			rightPtr++;
		}
		arrayPtr++;
	}

	while (leftPtr < leftSide.size()) {
		array[arrayPtr] = leftSide[leftPtr];
		++arrayPtr;
		++leftPtr;
	}

	while (rightPtr < rightSide.size()) {
		array[arrayPtr] = rightSide[rightPtr];
		arrayPtr++;
		rightPtr++;
	}
}

void mergeSort(vector<int> &array, int low, int high) {
	if (low < high) {
		int mid = low + (high - low) / 2;
		mergeSort(array, low, mid);
		mergeSort(array, mid + 1, high);
		merge(array, low, mid, high);
	}
}

vector<int> mergeSort(vector<int> array) {
	mergeSort(array, 0, array.size() - 1);
	return array;
}

