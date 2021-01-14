#include <vector>

using namespace std;

string runLengthEncoding(string str) {
	vector<char> answerString;
	int charCount = 1;

	for (int i = 1; i < str.length(); ++i) {
		char currentChar = str[i];
		char prevChar = str[i - 1];

		if (prevChar != currentChar || charCount == 9) {
			answerString.push_back(to_string(charCount)[0]);
			answerString.push_back(prevChar);
			charCount = 0;
		}
		++charCount;
	}
	answerString.push_back(to_string(charCount)[0]);
	answerString.push_back(str[str.length() - 1]);

	string encodedString(answerString.begin(), answerString.end());
	return encodedString;
}