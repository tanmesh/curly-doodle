#include <bits/stdc++.h>

using namespace std; 

#define all(a)          a.begin(), a.end()
#define allr(a)         a.rbegin(), a.rend()
#define F				first
#define S				second
#define pb              push_back
#define ll				long long
#define f(i, a, n)		for(int i=a; i<n; ++i)
// #define find(a, b)		(find(a.begin(), a.end(), b) == a.end())		
#define fast 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define watch(x) 		cout << (#x) << " is " << (x) << endl

void solve() {
	int N;
    cin >> N;
    vector<int> A(N);
 
    for (int &a : A)
        cin >> a;
 
    vector<int> prefix_sum(N + 1, 0);
 
    for (int i = 0; i < N; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + A[i];
    }
 
    vector<bool> special(N + 1, false);
 
    for (int i = 0; i < N; i++) {
        for (int j = i + 2; j <= N ; j++) {
        	if(prefix_sum[j] - prefix_sum[i] <= N) {
        		special[prefix_sum[j] - prefix_sum[i]] = true;	
        	} else {
        		break;
        	}
        }
    }
            
 
    int total = 0;
 
    for (int a : A)
        total += special[a];
 
    cout << total << '\n';
}

int main () {
  	fast
  	int t;
  	cin >> t;
  	while(t--) {
  		solve();
  	}
	return 0;
}