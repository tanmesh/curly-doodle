using namespace std;

bool isPalindrome(string str) {
	int strLen = str.length();
	int leftPtr = 0, rightPtr = strLen - 1;
	while (leftPtr <= rightPtr) {
		if (str[leftPtr] != str[rightPtr]) {
			return false;
		}
		++leftPtr;
		--rightPtr;
	}
	return true;
}

