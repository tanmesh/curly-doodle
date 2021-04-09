#include <vector>
using namespace std;

int getMaxSubsetSum(int i, int prevTaken, vector<int>& array, int dp[][2]) {
	int& result = dp[i][prevTaken];
	if(result == -1) {
		if(i >= array.size()) {
			return 0;
		}
		
		int notTaken = 0, taken = 0;
		
		if(prevTaken == 0) {
			taken = array[i] + getMaxSubsetSum(i + 1, 1, array, dp);
		}
		notTaken = getMaxSubsetSum(i + 1, 0, array, dp);
		
		result = max(notTaken, taken);
	}
	return result;
}

int maxSubsetSumNoAdjacent(vector<int> array) {
	int dp[1000][2];
	
	memset(dp, -1, sizeof(dp));
	
	return getMaxSubsetSum(0, 0, array, dp);
}