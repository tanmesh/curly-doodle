#include <vector>
using namespace std;

void generateDivtagsFromPrefix(int openingTagsNeeded, int closingTagsNeeded, string prefix, vector<string> &result) {
	if(openingTagsNeeded > 0)	{
		generateDivtagsFromPrefix(openingTagsNeeded - 1, closingTagsNeeded, prefix + "<div>", result);
	}
	if(openingTagsNeeded < closingTagsNeeded)	{
		generateDivtagsFromPrefix(openingTagsNeeded, closingTagsNeeded - 1, prefix + "</div>", result);
	}
	if(closingTagsNeeded == 0) {
		result.push_back(prefix);
	}
}

vector<string> generateDivTags(int numberOfTags) {
  vector<string> result;
	generateDivtagsFromPrefix(numberOfTags, numberOfTags, "", result);
	return result;
}
