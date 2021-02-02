// Solution 2: O(N)T, O(1)S
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


// // Solution 1: O(N)T, O(N)S
// using namespace std;

// int getNextId(int currId, vector<int> &array) {
// 	int N = (int)array.size();
// 	int jump = array[currId];
// 	int nextId = (currId + jump) % N;
// 	return nextId >= 0 ? nextId : nextId + N;
// }

// bool hasSingleCycle(vector<int> array) {
//   vector<int> freqTable(array.size(), 0);

// 	int i = 0, numElementsVisited = 0;
// 	while(1) {
// 		if(freqTable[i]+1 > 1) {
// 			if(i == 0 && numElementsVisited == (int)array.size()) {
// 				return true;
// 			} else {
// 				return false;
// 			}
// 		}
// 		++freqTable[i];
// 		++numElementsVisited;

// 		i = getNextId(i, array);
// 	}

// 	return true;
// }