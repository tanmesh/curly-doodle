#include <vector>
using namespace std;


// O(N)T, O(1)S
void twoSum(vector<int> &array, vector<vector<int>> &triples, int firstElement, int targetSum, int start, int end) {
	int i = start, j = end;

	while (i < j) {
		if (array[i] + array[j] == targetSum) {
			vector<int> tmp = vector<int> {firstElement, array[i], array[j]};
			triples.push_back(tmp);
			i += 1, j = end;
			continue;
		}

		if (array[i] + array[j] < targetSum) {
			++i;
		} else {
			--j;
		}
	}
}


// O(NlogN + N*N)T ==> O(N^2)T, O(N)S
vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
	sort(array.begin(), array.end());

	vector<vector<int>> triples;
	for (int i = 0; i < array.size(); ++i) {
		int remainingSum = targetSum - array[i];
		twoSum(array, triples, array[i], remainingSum, i + 1, array.size() - 1);
	}

	return triples;
}

