#include <vector>
using namespace std;

void buildPowerSet(int i, vector<int> &array, vector<int> subset, vector<vector<int>>& result) {
	if(i == array.size()) {
		result.push_back(subset);
		return;
	}	
	
	buildPowerSet(i + 1, array, subset, result);
	subset.push_back(array[i]);
	buildPowerSet(i + 1, array, subset, result);
}

vector<vector<int>> powerset(vector<int> array) {
	vector<vector<int>> result;
	
	buildPowerSet(0, array, {}, result);

  return result;
}
