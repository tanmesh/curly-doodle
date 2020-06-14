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
  	int n, k, q;
  	int N = 200000+1;
  	cin >> n >> k >> q;
  	vector<int> arr(N, 0);
  	for(int i=0; i<n; ++i) {
  		int l, r;
  		cin >> l >> r;
  		++arr[l];
  		--arr[r+1];
  	}
  	for(int i=1; i<N; ++i) {
  		arr[i] += arr[i-1];
  	}
  	for(int i=0; i<N; ++i) {
  		if(arr[i] >= k) {
  			arr[i] = 1;
  		} else {
  			arr[i] = 0;
  		}
  	}
  	for(int i=1; i<N; ++i) {
  		arr[i] += arr[i-1];
  	}
  	for(int i=0; i<q; ++i) {
  		int l, r;
  		cin >> l >> r;
  		cout << arr[r] - arr[l-1] << endl;;
  	}
	return 0;
}