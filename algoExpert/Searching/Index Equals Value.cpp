#include <vector>
using namespace std;

int indexEqualsValue(vector<int> array) {
  int low = 0, high = array.size() - 1;
	while(low <= high) {
		int mid = low + (high - low)/2;
		if(mid == array[mid]) {
			high = mid - 1;
		} else if(mid > array[mid]) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	
	if(low >= array.size() || low != array[low]) {
		return -1;
	}
	
  return low ;
}

// #include <vector>
// using namespace std;

// int indexEqualsValue(vector<int> array) {
//   for(int i=0; i<array.size(); ++i) {
// 		if(i == array[i]) {
// 			return i;
// 		}
// 	}
//   return -1;
// }
