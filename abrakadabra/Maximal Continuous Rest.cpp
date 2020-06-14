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
  	vector<int> input(n), working_hr_frq(n, 0);
  	for(int i=0; i<n; ++i) {
  		cin >> input[i];
  	}
  	int ans = 0, cnt = 0;
  	for(int i=0; i<2*n; ++i) {
		if(input[i%n] == 1) {
  			++cnt;
  			ans = max(ans, cnt);
  		} else {
  			cnt = 0;
  		}
  	}
  	cout << ans << endl;
	return 0;
}