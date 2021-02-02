// Solution 3: // O(N)T, O(N)S
#include <vector>

using namespace std;

// O(N)T, O(N)S
vector<int> arrayOfProducts(vector<int> array) {
	vector<int> product(array.size(), 1);

	int leftRunningProduct = 1;
	for (int i = 0; i < array.size(); ++i) {
		product[i] *= leftRunningProduct;
		leftRunningProduct *= array[i];
	}

	int rightRunningProduct = 1;
	for (int i = array.size() - 1; i >= 0; --i) {
		product[i] *= rightRunningProduct;
		rightRunningProduct *= array[i];
	}

	return product;
}


// // Solution 2: // O(N)T, O(N)S
// #include <vector>

// using namespace std;

// vector<int> arrayOfProducts(vector<int> array) {
//   vector<int> product(array.size(), 1);
// 	vector<int> leftHandSide(array.size(), 1);
// 	vector<int> rightHandSide(array.size(), 1);

// 	int lastId = array.size()-1;
// 	leftHandSide[0] = array[0];
// 	rightHandSide[lastId] = array[lastId];

// 	for(int i=1; i<array.size(); ++i) {
// 		leftHandSide[i] = leftHandSide[i-1] * array[i];
// 	}

// 	for(int i=lastId-1; i>=0; --i) {
// 		rightHandSide[i] = rightHandSide[i+1] * array[i];
// 	}

// 	product[0] = rightHandSide[1];
// 	product[lastId] = leftHandSide[lastId-1];
// 	for(int i=1; i<lastId; ++i) {
// 		product[i] = leftHandSide[i-1] * rightHandSide[i+1];
// 	}

// 	return product;
// }


// // Solution 1 // O(N^2)T, O(1)S
// #include <vector>

// using namespace std;

// vector<int> arrayOfProducts(vector<int> array) {
// 	vector<int> ans(array.size());

// 	for (int i = 0; i < array.size(); ++i) {
// 		long long int runningProd = 1;
// 		for (int j = 0; j < array.size(); ++j) {
// 			if (j != i) {
// 				runningProd *= array[j];
// 			}
// 		}
// 		ans[i] = runningProd;
// 	}

// 	return ans;
// }

