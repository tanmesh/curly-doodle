#include <bits/stdc++.h>

#define all(a)                      a.begin(), a.end()
#define allr(a)                      a.rbegin(), a.rend()
#define F							first
#define S							second
#define pb                          push_back
#define ll							long long
#define f(i, a, n)					for(int i=a; i<n; ++i)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std; 

int main () {
    fast
    int t;
    cin >> t;
    while(t--) {
    	for (int i = 0; i < 9; ++i) {
			string s;
			cin >> s;
			for (auto c : s) if (c == '2') c = '1';
			cout << s << endl;
		}
    }
	return 0;
}