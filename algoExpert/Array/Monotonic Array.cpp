// Solution 3
using namespace std;

bool isMonotonic(vector<int> array) {
	bool isNonDecr = true;
	bool isNonIncr = true;

	for (int i = 1; i < array.size(); ++i) {
		if (array[i - 1] < array[i]) {
			isNonDecr = false;
		}
		if (array[i - 1] > array[i]) {
			isNonIncr = false;
		}
	}
	return isNonIncr || isNonDecr;
}

// // Solution 1
// using namespace std;

// bool breakDir(int dir, int prevInt, int currInt) {
// 	int diff = currInt - prevInt;
// 	if (dir > 0) {
// 		return diff < 0;
// 	}
// 	return diff > 0;
// }

// bool isMonotonic(vector<int> array) {
// 	if (array.size() <= 2) {
// 		return true;
// 	}

// 	int dir = array[1] - array[0];

// 	for (int i = 2; i < array.size(); ++i) {
// 		if (dir == 0) {
// 			dir = array[i] - array[i - 1];
// 			continue;
// 		}

// 		if (breakDir(dir, array[i - 1], array[i])) {
// 			return false;
// 		}
// 	}
// 	return true;
// }

