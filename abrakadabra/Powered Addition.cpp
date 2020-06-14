// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>
#define all(a)                      a.begin(), a.end()
#define allr(a)                      a.rbegin(), a.rend()
#define 							first
#define S							second
#define pb                          push_back
#define ll							long long
#define f(i, n)					for(int i=0; i<n; ++i)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std; 

int main () {
    fast
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	f(i, n) {
    		cin >> a[i];
    	}
    	int last_max = a[0], max_diff = 0;
		for(int i = 1; i<n; ++i) {
			if (a[i] < last_max) {
				max_diff = max(max_diff, last_max - a[i]);
			}
			else {
				last_max = a[i];
			}
		}
 
		printf("%d\n", int(ceil(log2(max_diff+1))));
    }
	return 0;
}