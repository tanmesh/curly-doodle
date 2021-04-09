#include <vector>
using namespace std;

int dp[10000][10000];

int helper(int i, int target, vector<int>& denoms) {
	int& result = dp[i][target];
	
	if(result == -1) {
		result = 0;
		
		if(i == denoms.size()) {
			result = 0;
		} else if(target == 0) {
			result = 1;
		} else {
			int taken = 0, notTaken = 0;
			if(target - denoms[i] >= 0) {
				taken = helper(i, target - denoms[i], denoms);
			}
			notTaken = helper(i + 1, target, denoms);
			
			result = taken + notTaken;
		}
	}
	
  return result;
}

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
	memset(dp, -1, sizeof(dp));
	return helper(0, n, denoms);
}
