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

vector<int> sieveOfEratosthenes(int n) {
	vector<int> prime;
	vector<bool> isPrime(n + 1, true);

	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i * i <= n; ++i) {
		if (isPrime[i] == true) {
			for (int j = i * i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}

	for (int i = 0; i <= n; ++i) {
		if (isPrime[i]) {
			prime.push_back(i);
		}
	}
	return prime;
}

int main () {
	fast
	int n;
	cin >> n;
	vector<int> prime = sieveOfEratosthenes(n);
	for (int i = 0; i < prime.size(); ++i) {
		cout << prime[i] << " ";
	}
	cout << endl;
	return 0;
}