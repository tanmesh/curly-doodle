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
  	n = 2*n;
  	vector<int> input(n);
  	for(int i=0; i<n; ++i) {
  		cin >> input[i];
  	}
  	sort(all(input));
  	int ans = INT_MAX;
  	for(int i=0; i<n; ++i) {
  		for(int j=i+1; j<n; ++j) {
  			vector<int> tmp;
  			for(int k=0; k<n; ++k) {
  				if(k != i && k != j) {
  					tmp.push_back(input[k]);
  				}
  			}
  			int diff = 0;
  			for(int k=0; k+1<tmp.size(); k += 2) {
  				// cout << tmp[k] << " " << tmp[k+1] << endl;
  				diff += abs(tmp[k]-tmp[k+1]);
  			}
  			ans = min(ans, diff);
  		}
  	}
  	cout << ans << endl;
	return 0;
}