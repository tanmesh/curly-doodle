using namespace std;

bool breakDir(int dir, int prevInt, int currInt) {
	int diff = currInt - prevInt;
	if (dir > 0) {
		return diff < 0;
	}
	return diff > 0;
}

bool isMonotonic(vector<int> array) {
	if (array.size() <= 2) {
		return true;
	}

	int dir = array[1] - array[0];

	for (int i = 2; i < array.size(); ++i) {
		if (dir == 0) {
			dir = array[i] - array[i - 1];
			continue;
		}

		if (breakDir(dir, array[i - 1], array[i])) {
			return false;
		}
	}
	return true;
}

