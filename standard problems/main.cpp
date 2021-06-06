#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

#include "trie.h"

using namespace std;

int main() {
	Trie* root = new Trie();

	vector<string> words = {"the","a","there","answer","any","by","bye","their"};

	for(auto word: words) {
		root->insert(word);
	}

	cout << root->search("thee") << endl;
	return 0;
}