#include <bits/stdc++.h>
using namespace std;
vector<string> vec_splitter(string s) {
	for(char& c: s) c = c == ','?  ' ': c;
	stringstream ss; ss << s;
	vector<string> res;
	for(string z; ss >> z; res.push_back(z));
	return res;
}
void debug_out(vector<string> args, int idx) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, Head H, Tail... T) {
	if(idx > 0) cerr << ", ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, T...);
}
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __VA_ARGS__)
#else
#define debug(...) 42
#endif
int main() {
	int x = -1, y = 10000;
	double z = 0.2;
	string s = "beginner1010";
	long long b = 1LL << 60;
	debug(x, y, z, s, b);
	return 0;
}