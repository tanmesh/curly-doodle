#include <bits/stdc++.h>

using namespace std;

#define all(a)          a.begin(), a.end()
#define allr(a)         a.rbegin(), a.rend()
#define F				first
#define S				second
#define pb              push_back
#define ll				long long
#define fast 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define watch(x) 		cout << (#x) << " is " << (x) << endl

void print_(vector<int>& a) {
	for (auto& i : a)	 {
		cout << i << " ";
	}
	cout << endl;
}

int main () {
	fast
	vector<int> a = {1, 3, 4, 5};

	cout << a.size() << endl;
	for (int i = 0; i < a.size(); ++i) {
		cout << i << endl;
		a.erase(a.begin());
		print_(a);
	}
	cout << *a.begin() << endl;
	return 0;
}