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
  	int beds, pillow, frodo_pos;
  	cin >> beds >> pillow >> frodo_pos;
  	
  	if(beds == pillow) {
  		cout << 1 << endl;
  		return 0;
  	}
	
	pillow -= beds + 1;

  	int frodo_beds = 2;
  	int left_pr = max(1, frodo_pos - 1);
  	int right_pr = min(frodo_pos + 1, beds);

  	while(pillow >= (right_pr - left_pr + 1) && (left_pr > 1 || right_pr < beds)) {
  		pillow -= (right_pr - left_pr + 1);
  		if(left_pr > 1) {
  			--left_pr;
  		}
  		if(right_pr < beds) {
  			++right_pr;
  		}
  		++frodo_beds;
  	}

  	frodo_beds += pillow/(right_pr - left_pr + 1);
  	cout << frodo_beds << endl;
	return 0;
}