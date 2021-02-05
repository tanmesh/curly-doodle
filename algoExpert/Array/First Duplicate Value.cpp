// Solution 2, O(N)T, O(1)S
#include <vector>
using namespace std;

int firstDuplicateValue(vector<int> array) {
	for (auto it : array) {
		int absValue = abs(it);
		if (array[absValue - 1] < 0) {
			return absValue;
		}
		array[absValue - 1] *= -1;
	}
	return -1;
}


// // Solution 1, O(N)T, O(N)S
// #include <vector>
// using namespace std;

// int firstDuplicateValue(vector<int> array) {
// 	unordered_set<int> visited;
// 	for (int i = 0; i < array.size(); ++i) {
// 		if (visited.find(array[i]) == visited.end()) {
// 			visited.insert(array[i]);
// 		} else {
// 			return array[i];
// 		}
// 	}
// 	return -1;
// }

