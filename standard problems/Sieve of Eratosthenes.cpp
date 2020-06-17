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
	vector<bool> isPrime(n, false);

	for (int i = 2; i <= n; ++i) {
		if (isPrime[i] == false) {
			isPrime[i] = true;
			prime.push_back(i);

			for (int j = i + i; j <= n; j += i) {
				isPrime[j] = true;
			}
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