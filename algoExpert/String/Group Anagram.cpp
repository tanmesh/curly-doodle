#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
	unordered_map<string, vector<string>> anagram;

	for (auto word : words) {
		string sortedWord = word;
		sort(sortedWord.begin(), sortedWord.end());

		if (anagram.find(sortedWord) != anagram.end()) {
			anagram[sortedWord].push_back(word);
		} else {
			anagram[sortedWord] = vector<string> {word};
		}
	}

	vector<vector<string>> requiredAnswer;
	for (auto it : anagram) {
		requiredAnswer.push_back(it.second);
	}

	return requiredAnswer;
}

