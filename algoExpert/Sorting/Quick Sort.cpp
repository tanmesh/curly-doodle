#include <vector>
using namespace std;

int makePartition(vector<int> &array, int startId, int endId) {
	int pivot = startId;
	int rightHandSideId = pivot + 1;
	int leftHandSideId = rightHandSideId;

	while (rightHandSideId <= endId) {
		if (array[pivot] > array[rightHandSideId]) {
			swap(array[leftHandSideId], array[rightHandSideId]);
			++leftHandSideId;
		}
		++rightHandSideId;
	}
	swap(array[pivot], array[leftHandSideId - 1]);
	return leftHandSideId - 1;
}

void quickSort(vector<int> &array, int startId, int endId) {
	if (startId <= endId) {
		int pivot = makePartition(array, startId, endId);
		quickSort(array, startId, pivot - 1);
		quickSort(array, pivot + 1, endId);
	}
}

vector<int> quickSort(vector<int> array) {
	quickSort(array, 0, array.size() - 1);
	return array;
}

