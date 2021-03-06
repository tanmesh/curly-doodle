using namespace std;

bool generateDocument(string characters, string document) {
  unordered_map<char, int> hashMap;
	for(auto ch: characters) {
		hashMap[ch]++;
	}
	
	for(auto ch: document) {
		hashMap[ch]--;
	}
	
	for(auto it: hashMap) {
		if(it.second < 0) {
			return false;
		}
	}
  return true;
}
