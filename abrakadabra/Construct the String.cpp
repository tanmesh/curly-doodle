// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string.h>
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
    	int n, a, b;
    	cin >> n >> a >> b;
    	string ans;
    	int tmp = 0, i = 0;
    	for(i = 0; i<a; ++i) {
    		ans += 'a'+tmp;
    		tmp = (tmp+1)%b;
    	}
    	while(i < n) {
    		ans += 'a'+tmp;
    		tmp = (tmp+1)%b;	
    		i++;
    	}
    	cout << ans << endl;
    }
	return 0;
}