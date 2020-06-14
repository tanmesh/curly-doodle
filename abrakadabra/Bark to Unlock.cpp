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
  	string input;
  	cin >> input;

  	string input2 = input;
  	char ch = input[0];
  	input2[0] = input[1];
  	input2[1] = ch;

  	int n;
  	cin >> n;
  	vector< string > arr;
  	int cnt0 = 0, cnt1 = 0;
  	for(int i=0; i<n; ++i) {
  		string tmp;
  		cin >> tmp;
  		arr.push_back(tmp);
  		if(tmp == input) {
  			cout << "YES\n";
  			return 0;
  		}
  		if(input2[0] == tmp[0]) {
  			++cnt0;
  		}
  		if(input2[1] == tmp[1]) {
  			++cnt1;
  		}
  		if(cnt0 > 0 && cnt1 > 0) {
	  		cout << "YES\n";
	  		return 0;
	  	}
  	}
  	cout << "NO\n";
	return 0;
}