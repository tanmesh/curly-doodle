#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array) {
	for (int i = 0; i < array.size(); ++i) {
		bool atleastOneSwap = false;
		for (int j = 0; j + 1 < array.size() - i; ++j) {
			if (array[j] > array[j + 1]) {
				atleastOneSwap = true;
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
		if (atleastOneSwap == false) {
			return array;
		}
	}

	return array;
}

