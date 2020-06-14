// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define all(a)                      a.begin(), a.end()
#define allr(a)                      a.rbegin(), a.rend()
#define 							first
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
    	int n;
    	cin >> n;
    	if(n%2 == 0) {
    		cout << n/2-1 << endl;
    	} else {
    		cout << (int)(n/2) << endl;
    	}
    }
	return 0;
}