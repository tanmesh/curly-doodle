#include <vector>

using namespace std;

vector<int> getLongestPalindromeFrom(string str, int leftPtr, int rightPtr) {
	while (leftPtr >= 0 && rightPtr < str.length()) {
		if (str[leftPtr] != str[rightPtr]) {
			break;
		}
		--leftPtr;
		++rightPtr;
	}
	return vector<int> {leftPtr + 1, rightPtr};
}

string longestPalindromicSubstring(string str) {
	vector<int> currentLongest{0, 1};
	for (int i = 1; i < str.length(); ++i) {
		vector<int> odd = getLongestPalindromeFrom(str, i - 1, i + 1);
		vector<int> even = getLongestPalindromeFrom(str, i - 1, i);
		vector<int> longest = odd[1] - odd[0] > even[1] - even[0] ? odd : even;
		currentLongest = currentLongest[1] - currentLongest[0] > longest[1] - longest[0] ? currentLongest : longest;
	}
	return str.substr(currentLongest[0], currentLongest[1] - currentLongest[0]);
}