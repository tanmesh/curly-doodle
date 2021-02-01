// Solution 2: using 2 ptr //O(NlogN + N)T ==> O(NlogN)T, O(1)S
#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
	sort(array.begin(), array.end());
	int i = 0, j = array.size() - 1;

	while (i < j) {
		int currentSum = array[i] + array[j];
		if (currentSum == targetSum) {
			return vector<int> {array[i], array[j]};
		} else if (currentSum < targetSum) {
			++i;
		} else {
			--j;
		}
	}
	return {};
}


// // Solution 1: findinf all pairs and checking their sum // O(N^2)T, O(1)S
// #include <vector>
// using namespace std;

// vector<int> twoNumberSum(vector<int> array, int targetSum) {
// 	for (int i = 0; i < array.size(); ++i) {
// 		for (int j = i + 1; j < array.size(); ++j) {
// 			if (array[i] + array[j] == targetSum) {
// 				return vector<int> {array[i], array[j]};
// 			}
// 		}
// 	}
// 	return {};
// }

