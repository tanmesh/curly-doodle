#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#define all(a)                      a.begin(), a.end()
#define allr(a)                      a.rbegin(), a.rend()
#define F							first
#define S							second
#define pb                          push_back
#define ll							long long
#define f(i, a, n)					for(int i=a; i<n; ++i)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std; 

const int N = 2e5 + 7;
 
int n, k, d[N], sm[N];
vector<int> edges[N];
vector<pair<int, int>> vec;

void dfs(int v, int f = 0) {
    for(auto u: edges[v]) {
    	if(u == 0) {continue;}
        d[u] = d[v] + 1;
        dfs(u, v);
        sm[v] += sm[u];
    }
    vec.pb({d[v] - sm[v], v});
    sm[v]++;
}
 

int main () {
    fast
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].pb(b);
        edges[b].pb(a);
    }

    dfs(1);



	return 0;
}