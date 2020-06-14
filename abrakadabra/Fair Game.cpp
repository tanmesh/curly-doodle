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
  	for(int i=0; i<n; ++i) {
  		int a;
  		cin >> a;
  		++mp[a];
  	}
  	if(mp.size() == 2) {
  		int i = 0, check;
  		vector<int> ans;
  		for(auto value: mp) {
  			if(i++ == 0) {	
  				check = value.S;
  				ans.push_back(value.F);
  			} else if(check == value.S) {
  				ans.push_back(value.F);
  			} else {
  				cout << "NO\n";
  				return 0;
  			}
  		}
  		cout << "YES\n";
  		for(auto i: ans) {
  			cout << i << " ";
  		}
  		cout << endl;
  	} else {
  		cout << "NO\n";
  	}
	return 0;
}