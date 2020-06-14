// #include <bits/stdc++.h>

// using namespace std; 

// #define all(a)          a.begin(), a.end()
// #define allr(a)         a.rbegin(), a.rend()
// #define F				first
// #define S				second
// #define pb              push_back
// #define ll				long long
// #define f(i, a, n)		for(int i=a; i<n; ++i)
// #define find(a, b)		(find(a.begin(), a.end(), b) == a.end())		
// #define fast 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define watch(x) 		cout << (#x) << " is " << (x) << endl

// int main () {
//   	fast
//   	ll n, q;
//   	cin >> n >> q;
//   	for(ll i=0; i<q; ++i) {
//   		ll input;
//   		cin >> input;
//   		if(input%2 == 0) {
//   			while(input%2 == 0) {
//   				input = input/2 + n;
//   			}
//   		}
//   		cout << (input+1)/2 << endl;
//   	}
// 	return 0;
// }
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
  	ll n, q;
  	cin >> n >> q;
  	vector<ll> arr(2*n, 0);
  	for(ll i=1; i<=n; ++i) {
  		arr[2*i - 1] = i;
  	}
  	for(ll i=0; i<q; ++i) {
  		ll input;
  		cin >> input;
  		if(input%2 == 0) {
  			while(input%2 == 0) {
  				input = input/2 + n;
  			}
  		}
  		cout << arr[input] << endl;
  	}
	return 0;
}