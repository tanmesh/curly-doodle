#include <vector>
using namespace std;

int shiftedBinarySearch(vector<int> array, int target) {
  int low = 0, high = array.size() - 1;
	while(low <= high) {
		int mid = low + (high - low)/2;
		if(array[mid] == target) {
			return mid;
		} else if(array[low] <= array[mid]) {
			if(array[low] <= target && target <= array[mid]) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		} else {
			if(array[mid] <= target && target <= array[high]) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
	}
  return -1;
}
