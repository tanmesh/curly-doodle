#include <vector>
using namespace std;

int findSmallestElementId(vector<int> &array, int startId) {
	int minElementId = startId;
	for (int i = startId; i < array.size(); ++i) {
		if (array[i] < array[minElementId]) {
			minElementId = i;
		}
	}
	return minElementId;
}

vector<int> selectionSort(vector<int> array) {
	for (int i = 0; i < array.size(); ++i) {
		int j = findSmallestElementId(array, i);
		swap(array[i], array[j]);
	}
	return array;
}

