#include <vector>
using namespace std;

class cmp {
public:
	bool operator() (const int& a, const int& b) const {
		return a > b;
	}
};

vector<int> sortKSortedArray(vector<int> array, int k) {
	typedef priority_queue<int, vector<int>, cmp> my_pq;
	my_pq pq;

	vector<int> result;
	for (auto it : array) {
		pq.push(it);
		if (pq.size() > k) {
			result.push_back(pq.top());
			pq.pop();
		}
	}
	while (!pq.empty()) {
		result.push_back(pq.top());
		pq.pop();
	}
	return result;
}

