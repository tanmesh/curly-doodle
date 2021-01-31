// Solution 2: sending index. // (#nodes^2)T, O(height)S
#include <vector>

using namespace std;

int getNextSmallerId(vector<int> &array, int arrayId, int min, int max) {
	for (int i = arrayId + 1; i < array.size(); ++i) {
		if (array[i] < array[arrayId] && array[i] >= min) {
			return i;
		}
	}
	return -1;
}

int getNextLargerId(vector<int> &array, int arrayId, int min, int max) {
	for (int i = arrayId + 1; i < array.size(); ++i) {
		if (array[i] >= array[arrayId] && array[i] < max) {
			return i;
		}
	}
	return -1;
}

bool checkBothBstSame(vector<int> &arrayOne, vector<int> &arrayTwo, int arrayOneId, int arrayTwoId, int min, int max) {
	/*
	if(arrayOne.size() != arrayTwo.size()) {
		return false;
	}

	if(arrayOne.size() == 0 && arrayTwo.size() == 0) {
		return true;
	}

	code between lines 25- 31 are replaced by code between lines 36- 38.
	*/

	if (arrayOneId == -1 || arrayTwoId == -1) {
		return arrayOneId == arrayTwoId;
	}

	if (arrayOne[arrayOneId] != arrayTwo[arrayTwoId]) {
		return false;
	}

	int updatedMin = arrayOne[arrayOneId];
	int updatedMax = arrayOne[arrayOneId];

	int smallerOneId = getNextSmallerId(arrayOne, arrayOneId, min, updatedMax);
	int smallerTwoId = getNextSmallerId(arrayTwo, arrayTwoId, min, updatedMax);

	int largerOneId = getNextLargerId(arrayOne, arrayOneId, updatedMin, max);
	int largerTwoId = getNextLargerId(arrayTwo, arrayTwoId, updatedMin, max);

	bool leftSideSame = checkBothBstSame(arrayOne, arrayTwo, smallerOneId, smallerTwoId, min, updatedMax);
	bool rightSideSame = checkBothBstSame(arrayOne, arrayTwo, largerOneId, largerTwoId, updatedMin, max);

	return leftSideSame && rightSideSame;
}

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
	return checkBothBstSame(arrayOne, arrayTwo, 0, 0, INT_MIN, INT_MAX);
}

// // Solution 1: sending array. (#nodes^2)T, O(#nodes^2)S
// #include <vector>

// using namespace std;

// vector<int> getSmaller(vector<int> &array) {
// 	vector<int> smaller;
// 	for (int i = 1; i < array.size(); ++i) {
// 		if (array[0] > array[i]) {
// 			smaller.push_back(array[i]);
// 		}
// 	}
// 	return smaller;
// }

// vector<int> getLarger(vector<int> &array) {
// 	vector<int> larger;
// 	for (int i = 1; i < array.size(); ++i) {
// 		if (array[0] <= array[i]) {
// 			larger.push_back(array[i]);
// 		}
// 	}
// 	return larger;
// }

// bool checkBothBstSame(vector<int> &arrayOne, vector<int> &arrayTwo) {
// 	if (arrayOne.size() != arrayTwo.size()) {
// 		return false;
// 	}

// 	if (arrayOne.size() == 0 && arrayTwo.size() == 0) {
// 		return true;
// 	}

// 	if (arrayOne[0] != arrayTwo[0]) {
// 		return false;
// 	}

// 	vector<int> smaller1 = getSmaller(arrayOne);
// 	vector<int> smaller2 = getSmaller(arrayTwo);

// 	vector<int> larger1 = getLarger(arrayOne);
// 	vector<int> larger2 = getLarger(arrayTwo);

// 	bool flagSmaller = checkBothBstSame(smaller1, smaller2);
// 	bool flagLarger = checkBothBstSame(larger1, larger2);

// 	return flagSmaller && flagLarger;
// }

// bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
// 	return checkBothBstSame(arrayOne, arrayTwo);
// }