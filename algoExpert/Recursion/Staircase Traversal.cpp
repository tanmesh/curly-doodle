

// using namespace std;

// // O(#steps * height)T, O(height)S
// int numberOfWaysToTop(int height, int maxSteps, unordered_map<int, int> &dp) {
// 	if(height < 0) {
// 		return 0;
// 	}
// 	if(dp.find(height) == dp.end()) {
		
// 		int result = 0;
// 		for(int step = 1; step <= maxSteps; ++step) {
// 			result += numberOfWaysToTop(height - step, maxSteps, dp);
// 		}
// 		dp[height] = result;
// 	}
	
//   return dp[height];
// }

// int staircaseTraversal(int height, int maxSteps) {
//   unordered_map<int, int> dp = {{0, 1}, {1, 1}};
	
// 	return numberOfWaysToTop(height, maxSteps, dp);
// }

// using namespace std;

// // O(#steps^height)T, O(height)S
// int staircaseTraversal(int height, int maxSteps) {
// 	if(height < 0) {
// 		return 0;
// 	}
// 	if(height == 0) {
// 		return 1;
// 	}
	
// 	int result = 0;
// 	for(int step = 1; step <= maxSteps; ++step) {
// 		result += staircaseTraversal(height - step, maxSteps);
// 	}
	
//   return result;
// }
