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
  	map<int, int> mp;
  	for(int i=0; i<n; ++i){
  		int tmp;
  		cin >> tmp;
  		++mp[tmp];
  	}
  	map<int, int> mp2;
  	for(int i=0; i<n-1; ++i){
  		int tmp;
  		cin >> tmp;
  		++mp[tmp];
  		++mp2[tmp];
  	}
  	for(auto i: mp) {
  		if(i.S%2 != 0) {
  			cout << i.F << endl;
  		}
  	}
  	for(int i=0; i<n-2; ++i){
  		int tmp;
  		cin >> tmp;
  		++mp2[tmp];
  	}
  	for(auto i: mp2) {
  		if(i.S%2 != 0) {
  			cout << i.F << endl;
  		}
  	}
	return 0;
}