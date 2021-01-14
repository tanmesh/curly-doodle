using namespace std;

string caesarCypherEncryptor(string str, int key) {
	key %= 26;
	for (int i = 0; i < str.length(); ++i) {
		int val = int(str[i]) + key;
		str[i] = val > 122 ? char(val - 26) : char(val);
	}
	return str;
}

