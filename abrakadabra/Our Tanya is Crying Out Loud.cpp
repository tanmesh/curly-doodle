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

long long n,a,b,k;
long long rec(long long n) {
	if(n<k | k==1) {
		return (n-1)*a;
	}
	if(n%k) {
		return rec(n-n%k) + n%k*a;
	}
	return rec(n/k) + min(b,a*(n-n/k));
}

int main () {
  	fast
  	cin >> n >> k >> a >> b;
  	cout << rec(n) << endl;
	return 0;
}