#include <vector>
using namespace std;

void getpermutationHelper(int i, vector<int> &array, vector<vector<int>> &result) {
	if(i == array.size() - 1) {
		result.push_back(array);
		return;
	}
	for(int j = i; j < array.size(); ++j) {
		swap(array[i], array[j]);
		getpermutationHelper(i + 1, array, result);
		swap(array[i], array[j]);
	}
}

vector<vector<int>> getPermutations(vector<int> array) {
  vector<vector<int>> result;
	getpermutationHelper(0, array, result);
  return result;
}
