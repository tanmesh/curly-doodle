#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
	int i = 0, j = array.size() - 1;
	while (i < j) {
		while (i < j && array[j] == toMove) {
			--j;
		}
		while (i < j && array[i] != toMove) {
			++i;
		}

		swap(array[i], array[j]);
		++i;
		--j;
	}
	return array;
}

