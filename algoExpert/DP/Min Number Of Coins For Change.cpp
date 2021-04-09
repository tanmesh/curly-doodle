#include <vector>
using namespace std;

long dp[1000][1000];

long helper(int i, int target, vector<int>& denoms) {
	long &numberOfCoinsRequired = dp[i][target];
	if(numberOfCoinsRequired == -1) {
		numberOfCoinsRequired = INT_MAX;
		if(target == 0) {
			numberOfCoinsRequired = 0;
		} else if(i >= denoms.size()) {
			numberOfCoinsRequired = INT_MAX;
		} else {
			if(target - denoms[i] >= 0) {
				numberOfCoinsRequired = min(numberOfCoinsRequired, 1 + helper(i, target - denoms[i], denoms));
			}
			numberOfCoinsRequired = min(numberOfCoinsRequired, helper(i + 1, target, denoms));
		}
	}
	
	return numberOfCoinsRequired;
}

int minNumberOfCoinsForChange(int target, vector<int> denoms) {
	memset(dp, -1, sizeof(dp));
	int numberOfCoinsRequired = helper(0, target, denoms);;
	if(numberOfCoinsRequired == INT_MAX) {
		return -1;
	}
	return numberOfCoinsRequired;
}
