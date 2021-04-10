using namespace std;

int getNumberOfWays(int i, int j, int width, int height, vector<vector<int>> &dp) {
	int& result = dp[i][j];
	if(result == -1) {
		result = 0;
		if(i == width - 1 && j == height - 1) {
			result = 1;
			return result;
		}
		if(i > width || j > height) {
			result = 0;
			return result;
		}
		result = getNumberOfWays(i + 1, j, width, height, dp) + getNumberOfWays(i, j + 1, width, height, dp);	
	}
	return result;
}

int numberOfWaysToTraverseGraph(int width, int height) {
	vector<vector<int>> dp(width + 1000, vector<int> (height + 1000, -1) );
	
	int i = 0, j = 0;
  int result = getNumberOfWays(i, j, width, height, dp);
  return result;
}
