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

int main () {
	fast
    int n;
    string input;
    cin >> n >> input;
    int cur = 0, ans = 0;

    map<int, int> m;
    m[0] = -1;
    for(int i=0; i<n; i++) {
        if(input[i] == '1')
            cur++;
        else
            cur--;
        if(m.find(cur) != m.end())
            ans=max(ans, i-m[cur]);     
        else
            m[cur]=i;
    }  

    cout<<ans;
    return 0;
}