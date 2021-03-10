#include <vector>
using namespace std;

int getLowerBound(vector<int> &array, int target) {
	int low = 0, high = array.size() - 1;
	while(low <= high) {
		int mid = low + (high - low)/2;
		if(array[mid] >= target) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	if(low < array.size() && target == array[low]) {
		return low;
	}
	return -1;
}

int getUpperBound(vector<int> &array, int target) {
	int low = 0, high = array.size() - 1;
	while(low <= high) {
		int mid = low + (high - low)/2;
		if(array[mid] <= target) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	if(high < array.size() && target == array[high]) {
		return high;
	}
	return -1;
}

vector<int> searchForRange(vector<int> array, int target) {
  	int lowerBound = getLowerBound(array, target);
	int upperBound = getUpperBound(array, target);
  	return {lowerBound, upperBound};
}
