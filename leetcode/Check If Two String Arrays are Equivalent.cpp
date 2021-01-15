class Solution {
public:
	bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
		string comparingString1 = "";
		string comparingString2 = "";

		for (auto word : word1) {
			comparingString1 += word;
		}

		for (auto word : word2) {
			comparingString2 += word;
		}

		int wordLength1 = comparingString1.length();
		int wordLength2 = comparingString2.length();

		if (wordLength1 != wordLength2) {
			return false;
		}
		for (int i = 0; i < wordLength2; ++i) {
			if (comparingString1[i] != comparingString2[i]) {
				return false;
			}
		}
		return true;
	}
};