#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

#define all(a)          a.begin(), a.end()
#define allr(a)         a.rbegin(), a.rend()
#define F				first
#define S				second
#define pb              push_back
#define ll				long long
#define fast 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define watch(x) 		cout << (#x) << " is " << (x) << endl

void print(vector<int>& input) {
	for(auto it: input) {
		cout << it << " ";
	}
	cout << endl;
}

int partition(vector<int>& input, int low, int high) {
	int pivot = low;
	int leftPtr = low, rightPtr = low+1;
	while(rightPtr <= high) {
		if(input[pivot] > input[rightPtr]) {
			++leftPtr;
			swap(input[leftPtr], input[rightPtr]);
		}
		++rightPtr;
	}
	swap(input[pivot], input[leftPtr]);
	return leftPtr;
}

void quicksort(vector<int>& input, int low, int high) {
	if(low < high) {
		int pivot = partition(input, low, high);
		quicksort(input, low, pivot - 1);
		quicksort(input, pivot + 1, high);
	}
}

void merge(vector<int>& input, int low, int mid, int high) {
	vector<int> leftHalf, rightHalf;
	int inputPtr = low;
	while (inputPtr <= mid) {
		leftHalf.push_back(input[inputPtr]);
		++inputPtr;
	}

	inputPtr = mid+1;
	while (inputPtr <= high) {
		rightHalf.push_back(input[inputPtr]);
		++inputPtr;
	}

	inputPtr = low;
	int leftPtr = 0, rightPtr = 0;
	while (leftPtr < leftHalf.size() && rightPtr < rightHalf.size()) {
		if (leftHalf[leftPtr] < rightHalf[rightPtr]) {
			input[inputPtr] = leftHalf[leftPtr];
			leftPtr++;
		} else {
			input[inputPtr] = rightHalf[rightPtr];
			rightPtr++;
		}
		++inputPtr;
	}

	while (leftPtr < leftHalf.size()) {
		input[inputPtr] = leftHalf[leftPtr];
		inputPtr++, leftPtr++;
	}

	while (rightPtr < rightHalf.size()) {
		input[inputPtr] = rightHalf[rightPtr];
		inputPtr++, rightPtr++; 
	}
}

void mergeSort(vector<int>& input, int low, int high) {
	if (low < high) {
		int mid = low + (high - low) / 2;
		mergeSort(input, low, mid);
		mergeSort(input, mid + 1, high);

		merge(input, low, mid, high);
	}
}

int main () {
	fast

	int N;
	cout << "Enter array length N:\n";
	cin >> N;
	vector<int> input(N);
	cout << "Enter array N elements:\n";
	for (int i = 0; i < N; ++i) {
		cin >> input[i];
	}

	vector<int> arr = input;
	cout << "QuickSort: Before array\n";
	print(arr);
	quicksort(arr, 0, N - 1);
	cout << "QuickSort: After array\n";
	print(arr);


	arr = input;
	cout << "Mergesort: Before array\n";
	print(arr);
	mergeSort(arr, 0, N - 1);
	cout << "Mergesort: After array\n";
	print(arr);
	return 0;
}