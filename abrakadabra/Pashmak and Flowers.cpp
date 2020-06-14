#include <bits/stdc++.h>

using namespace std;

#define all(a)          a.begin(), a.end()
#define allr(a)         a.rbegin(), a.rend()
#define F				first
#define S				second
#define pb              push_back
#define ll				long long
#define fast 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define watch(x) 		cout << (#x) << " is " << (x) << endl

int main () {
	fast
	ll n;
	cin >> n;
	map<ll, ll> beautiful;
	for (ll i = 0; i < n; ++i) {
		ll tmp;
		cin >> tmp;
		++beautiful[tmp];
	}
	auto first = beautiful.begin();
	auto second = beautiful.rbegin();
	ll diff = abs(first->F - second->F);
	ll com = first->S * (first->S - 1) / 2;
	if (first->F != second->F) {
		com = first->S * second->S;
	}


	cout << diff << " " << com << endl;
	return 0;
}