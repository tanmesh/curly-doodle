#include <vector>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
  vector<int> result = {INT_MIN, INT_MIN, INT_MIN};
	
	for(int j=result.size()-1; j>=0; --j) {
		int maxNumId = 0;
		for(int i=1; i<array.size(); ++i) {
			maxNumId = array[i] > array[maxNumId] ? i : maxNumId;
		}
		result[j] = array[maxNumId];
		array[maxNumId] = INT_MIN;
	}
	
  return result;
}
