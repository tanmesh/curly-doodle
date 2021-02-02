using namespace std;

int getNextId(int currId, vector<int> &array) {
	int N = (int)array.size();
	int jump = array[currId];
	int nextId = (currId + jump) % N;
	return nextId >= 0 ? nextId : nextId + N;
}

bool hasSingleCycle(vector<int> array) {
	int numElementsVisited = 0;
	int currId = 0;
	int N = (int)array.size();

	while (numElementsVisited < N) {
		if (numElementsVisited > 0 && currId == 0) {
			return false;
		}
		++numElementsVisited;
		currId = getNextId(currId, array);
	}

	return currId == 0;
}

