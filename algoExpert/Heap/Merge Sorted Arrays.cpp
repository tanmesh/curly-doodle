using namespace std;

class cmp {
public:
	bool operator() (const int& a, const int& b) const {
		return a > b;
	}
};

vector<int> mergeSortedArrays(vector<vector<int>> arrays) {
	typedef priority_queue<int, vector<int>, cmp> my_pq;
	my_pq pq;

	for (auto array : arrays) {
		for (auto it : array) {
			pq.push(it);
		}
	}
	vector<int> result;
	while (!pq.empty()) {
		int element = pq.top();
		result.push_back(element);
		pq.pop();
	}
	return result;
}

