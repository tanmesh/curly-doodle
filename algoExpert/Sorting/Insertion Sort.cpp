#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> array) {
	for (int i = 1; i < array.size(); ++i) {
		int j = i;
		while (j - 1 >= 0) {
			if (array[j - 1] > array[j]) {
				swap(array[j - 1], array[j]);
			}
			--j;
		}
	}
	return array;
}

