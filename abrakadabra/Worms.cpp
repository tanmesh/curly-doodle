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
  	vector<int> input(n);
  	cin >> input[0];
  	for(int i=1; i<n; ++i) {
  		cin >> input[i];
  		input[i] += input[i-1];
  	}

  	int m;
  	cin >> m;
  	for(int i=0; i<m; ++i) {
  		int query;
  		cin >> query;
  		cout << lower_bound(all(input), query) - input.begin() + 1<< endl;
  	}
	return 0;
}