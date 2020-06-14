#include <bits/stdc++.h>

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

int main () {
  	fast
  	int n;
  	cin >> n;
  	int b, x = 0, maxx_a = 0, a;
  	for(int i=0; i<n; ++i) {
  		cin >> b;
  		x = maxx_a;
  		a = b + x;
  		maxx_a = max(maxx_a, a);
  		cout << a << " ";
  	}
	return 0;
}