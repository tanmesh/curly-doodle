using namespace std;

int dp[10000][10000];

int editDistance(int left, int right, string str1, string str2) {	
	int& result = dp[left][right];
	
	if(result == -1) {
		if(left == str1.length()) {
			result = (int)str2.length() - right;
			return result;
		}
		if(right == str2.length()) {
			result = (int)str1.length() - left;
			return result;
		}
		
		if(str1[left] == str2[right]) {
			result = editDistance(left + 1, right + 1, str1, str2);
			return result;
		}
		
		int insertionCost = 1 + editDistance(left, right + 1, str1, str2);
		int deletionCost = 1 + editDistance(left + 1, right, str1, str2);
		int substitutionCost = 1 + editDistance(left + 1, right + 1, str1, str2);
		
		result = min({insertionCost, deletionCost, substitutionCost});
	}
	
	return result;
}

int levenshteinDistance(string str1, string str2) {
	memset(dp, -1, sizeof(dp));
	
	int left = 0, right = 0;
	int result = editDistance(left, right, str1, str2);
  return result;
}
