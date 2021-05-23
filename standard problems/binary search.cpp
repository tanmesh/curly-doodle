#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

#define all(a)          a.begin(), a.end()
#define allr(a)         a.rbegin(), a.rend()
#define F				first
#define S				second
#define pb              push_back
#define ll				long long
#define fast 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define watch(x) 		cout << (#x) << " is " << (x) << endl

int upperBound(vector<int>& input, int target) {
	int low = 0, high = input.size()-1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(input[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if(high >= 0 && high < input.size() && input[high] == target) {
        return high;
    }
    return -1;
}

int lowerBound(vector<int>& input, int target) {
	int low = 0, high = input.size()-1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(input[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if(low >= 0 && low < input.size() && input[low] == target) {
        return low;
    }
    return -1;
}

int binarySearch(vector<int>& input, int target) {
	int low = 0, high = input.size() - 1;
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (target == input[mid]) {
			return mid;
		} else if (target < input[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	if(low < input.size() && input[low] == target) {
		return low;
	}
	return -1;
}

int main () {
	fast
	cout << "Enter array length: ";
	int n;
	cin >> n;
	vector<int> input(n);
	cout << "Enter array elements: ";
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	cout << "Enter target value: ";
	int target;
	cin >> target;


	cout << "binary serch: " << binarySearch(input, target) << endl;
	cout << "lowerBound: " << lowerBound(input, target) << endl;
	cout << "upperBound: " << upperBound(input, target) << endl;
	return 0;
}









