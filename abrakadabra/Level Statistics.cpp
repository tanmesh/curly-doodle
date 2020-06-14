#include <iostream>
// #include <bits/stdc++.h>
#define all(a)                      a.begin(), a.end()
#define 							first
#define S							second
#define pb                          push_back
#define ll							long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std; 

int main () {
    fast
    int t;
    cin >> t;
    while(t--) {
        bool flag = true;
        int n;
        cin >> n;
        int p, c, pp, pc;
        pp = 0, pc = 0;
        for(int i=0; i<n; ++i) {
            cin >> p >> c;
            if(p < pp || c < pc || c - pc > p - pp) {
                flag = false;
            }
            pp = p, pc = c;
        }
        if(!flag) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
	return 0;
}