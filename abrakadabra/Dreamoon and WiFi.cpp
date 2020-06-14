#include <bits/stdc++.h>

using namespace std;

#define all(a)          a.begin(), a.end()
#define allr(a)         a.rbegin(), a.rend()
#define F				first
#define S				second
#define pb              push_back
#define ll				long long
#define fast 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<setprecision(12);
#define watch(x) 		cout << (#x) << " is " << (x) << endl

int main () {
	fast
	string send, recieve;
	cin >> send >> recieve;
	int position = 0;
	for (int i = 0; i < send.size(); ++i) {
		if (send[i] == '+') {
			++position;
		} else {
			--position;
		}
	}

	int recievePos = 0, spaces = 0;
	for (int i = 0; i < recieve.size(); ++i) {
		if (recieve[i] == '+') {
			++recievePos;
		}
		if (recieve[i] == '-') {
			--recievePos;
		}
		if (recieve[i] == '?') {
			++spaces;
		}
	}


	if (spaces == 0) {
		if (recievePos == position) {
			printf("%0.14f", 1.0 / 1);
			return 0;
		}
	}

	int deno = 0;
	while (spaces >= 0) {

		if (position == spaces + recievePos) {
			++deno;
		}
		if (position == (-1)*spaces + recievePos) {
			++deno;
		}
		spaces -= 2;
	}

	if (deno == 0) {
		printf("%0.14f", 0.0);
	} else {
		printf("%0.14f", 1.0 / deno);
	}

	return 0;
}