using namespace std;

string longestSubstringWithoutDuplication(string str) {
  unordered_map<char, int> hashMap;
	string longestNonDuplicateSubstring = "";
	int startIdx = 0;
	
	for(int i=0; i<str.length(); ++i) { // O(N)T
		if(hashMap.find(str[i]) != hashMap.end()) {
			string currentSubstr = str.substr(startIdx, i - 1 - startIdx + 1);
			longestNonDuplicateSubstring = longestNonDuplicateSubstring.length() < currentSubstr.length() ? currentSubstr : longestNonDuplicateSubstring;
			startIdx = hashMap[str[i]] + 1;
			i = startIdx;
			hashMap = {};
		}
		hashMap[str[i]] = i;
	}
	
	string currentSubstr = str.substr(startIdx, str.length() - 1 - startIdx + 1);
	longestNonDuplicateSubstring = longestNonDuplicateSubstring.length() < currentSubstr.length() ? currentSubstr : longestNonDuplicateSubstring;
	
  return longestNonDuplicateSubstring;
}
