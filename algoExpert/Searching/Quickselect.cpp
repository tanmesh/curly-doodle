#include <vector>
using namespace std;

int partition(vector<int> &array, int low, int high) {
	int pivot = low;
	int leftHalfEnd = low + 1;
	int rightHalfEnd = low + 1;
	while(rightHalfEnd <= high) {
		if(array[rightHalfEnd] < array[pivot]) {
			swap(array[rightHalfEnd], array[leftHalfEnd]);
				++leftHalfEnd;
		}
		++rightHalfEnd;
	}
	swap(array[pivot], array[leftHalfEnd - 1]);
	return leftHalfEnd - 1;
}

int quickselect(vector<int> array, int k) {
	int low = 0;
	int high = array.size() - 1;
	k = k - 1;
	
  while(true) {
		int pivot = partition(array, low, high);
		if(pivot == k) {
			return array[k];
		} else if(pivot < k) {
			low = pivot + 1;
		} else {
			high = pivot - 1;
		}
	}
	
  return -1;
}
