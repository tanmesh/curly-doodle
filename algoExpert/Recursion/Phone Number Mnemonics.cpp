#include <vector>
#include <unordered_map> 
using namespace std;

void buildPhoneNumberMnemonics(int i, string permutation, string &phoneNumber, 
															 unordered_map<int, string> &dailPad, vector<string> &result) {
	if(i == phoneNumber.length()) {
		result.push_back(permutation);
		return;
	}
	int num = phoneNumber[i] - '0';
	if(num < 2) {
		buildPhoneNumberMnemonics(i + 1, permutation + phoneNumber[i], phoneNumber, dailPad, result);
	} else {
		for(int j = 0; j < dailPad[num].length(); ++j) {
			buildPhoneNumberMnemonics(i + 1, permutation + dailPad[num][j], phoneNumber, dailPad, result);
		}
	}
}

vector<string> phoneNumberMnemonics(string phoneNumber) {
  unordered_map<int, string> dailPad = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"} };
	vector<string> result;
	
	buildPhoneNumberMnemonics(0, "", phoneNumber, dailPad, result);
	
  return result;
}
