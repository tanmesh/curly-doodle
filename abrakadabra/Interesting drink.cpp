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
  	vector<int> price_per_shop(n, 0);
  	for(int i=0; i<n; ++i) {
  		cin >> price_per_shop[i];
  	}
  	sort(all(price_per_shop));
  	int q;
  	cin >> q;
  	while(q--) {
  		int price;
  		cin >> price;
  		int index = upper_bound(all(price_per_shop), price) - price_per_shop.begin();
  		if(price == price_per_shop[index]) {
  			++index;
  		}
  		cout << index << endl;
  	}
	return 0;
}