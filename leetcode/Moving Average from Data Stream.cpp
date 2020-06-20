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

class MovingAverage {
public:
	deque<int> q;
	int N, maxN;

	MovingAverage(int size) {
		N = 0;
		maxN = size;
	}

	double next(int val) {
		N++;
		if (N > maxN) {
			q.pop_front();
		}
		q.push_back(val);

		double avg = 0;
		int cnt = 0;
		for (auto it : q) {
			avg += it;
			++cnt;
		}
		avg /= cnt;
		return avg;
	}
};

int main () {
	fast
	MovingAverage* obj = new MovingAverage(3);
	double param_1 = obj->next(1);
	cout << param_1 << endl;
	double param_2 = obj->next(10);
	cout << param_2 << endl;
	double param_3 = obj->next(3);
	cout << param_3 << endl;
	double param_4 = obj->next(5);
	cout << param_4 << endl;

	return 0;
}