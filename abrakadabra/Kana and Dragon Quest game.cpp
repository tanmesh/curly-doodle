#include <bits/stdc++.h>

#define all(a)                      a.begin(), a.end()
#define allr(a)                     a.rbegin(), a.rend()
#define F							first
#define S							second
#define pb                          push_back
#define ll							long long
#define f(i, a, n)					for(int i=a; i<n; ++i)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std; 

void solve() {
    int x, a, b;
    cin>> x >> a >> b;
    while(a-- && x >= 20){
        x = x/2 + 10;
    }
    if(x - b*10 <= 0){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
}


int main () {
    fast
    int t;
    cin >> t;
    while(t--) {
    	solve();
    }
	return 0;
}