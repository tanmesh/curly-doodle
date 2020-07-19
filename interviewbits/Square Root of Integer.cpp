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

bool f(int n, int target) {
	if (n <= target / n) {
		return true;
	}
	return false;
}

int sqrt(int target) {
	if (target <= 1) {
		return target;
	}
	int low = 1, high = target / 2;

	while (low < high) {
		int mid = low + (high - low + 1) / 2;
		if (f(mid, target) == true) {
			low = mid;
		} else {
			high = mid - 1;
		}
	}
	return low;
}


int main () {
	fast
	int n;
	cin >> n;
	cout << sqrt(n) << endl;
	return 0;
}