#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
#define all(a)                      a.begin(), a.end()
#define allr(a)                      a.rbegin(), a.rend()
#define 							first
#define S							second
#define pb                          push_back
#define ll							long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std; 

int main () {
    fast
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a;
        for(int i=0; i<n; ++i) {
            int tmp;
            cin >> tmp;
            a.pb(tmp);
        }
        sort(allr(a));
        int ans = 0, prev = 0;
        for(int i=0; i<a.size(); ++i) {
            prev += a[i];
            double d = prev/(i+1);
            if(d < double(x)) {
                break;
            }
            ans = i+1;
        }
        cout << ans << endl;
    }
	return 0;
}