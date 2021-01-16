#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isValidIPPart(string IPPart) {
	if (IPPart == "") {
		return false;
	}
	int IntIPPart = stoi(IPPart);

	if (IntIPPart > 255) {
		return false;
	}

	if (IPPart.length() != to_string(IntIPPart).length()) {
		return false;
	}

	return true;
}

vector<string> validIPAddresses(string s) {
	vector<string> allValidIPAdresses;

	for (int i = 0; i < min((int)s.length(), 4); ++i) {
		for (int j = i + 1; j < i + min((int)s.length() - i, 4); ++j) {
			for (int k = j + 1; k < j + min((int)s.length() - j, 4); ++k) {
				string x1 = s.substr(0, i);
				string x2 = s.substr(i, j - i);
				string x3 = s.substr(j, k - j);
				string x4 = s.substr(k);

				if (isValidIPPart(x1) && isValidIPPart(x2) && isValidIPPart(x3) && isValidIPPart(x4)) {
					x1 += ".";
					x1 += x2;
					x1 += ".";
					x1 += x3;
					x1 += ".";
					x1 += x4;
					allValidIPAdresses.push_back(x1);
				}
			}
		}
	}

	return allValidIPAdresses;
}

