#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define all(a)          a.begin(), a.end()
#define allr(a)         a.rbegin(), a.rend()
#define F				first
#define S				second
#define pb              push_back
#define ll				long long
#define f(i, a, n)		for(int i=a; i<n; ++i)
#define find(a, b)		(find(a.begin(), a.end(), b) == a.end())
#define fast 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define watch(x) 		cout << (#x) << " is " << (x) << endl

int gcd(int a, int b) {
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a == b)
		return a;
	if (a > b)
		return gcd(a - b, b);
	return gcd(a, b - a);
}

vector<string> simplifiedFractions(int n) {
	vector<string> s;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i < j && gcd(i, j) == 1) {
				string input = to_string(i) + "/" + to_string(j);
				s.push_back(input);
			}
		}
	}
	return s;
}

int main () {
	fast
	int n;
	cin >> n;
	vector<string> s = simplifiedFractions(n);
	for (int i = 0; i < s.size(); ++i) {
		cout << s[i] << endl;
	}
	return 0;
}