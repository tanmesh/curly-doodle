// // Solution 1: inserting the new interval and sorting it by compairing it with next element. and later, merging all possible.
// // O(N)T, O(1)S
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		intervals.push_back(newInterval);

		int i = intervals.size() - 1;
		while (i - 1 >= 0) {
			if (intervals[i - 1][0] > intervals[i][0]) {
				swap(intervals[i], intervals[i - 1]);
			} else {
				break;
			}
			--i;
		}

		vector<vector<int>> result;
		vector<int> currInterval = intervals[0];

		for (int i = 1; i < intervals.size(); ++i) {
			if (currInterval[0] < intervals[i][0] && currInterval[1] < intervals[i][0]) {
				// check for no overlapping
				result.push_back(currInterval);
				currInterval = intervals[i];
			} else {
				currInterval[0] = min(currInterval[0], intervals[i][0]);
				currInterval[1] = max(currInterval[1], intervals[i][1]);
			}
		}
		result.push_back(currInterval);

		return result;
	}
};

// // Solution 1: inserting the new interval and sorting it using sort(). and later, merging all possible.
// // O(NlogN)T, O(1)S
// class cmp {
// public:
//     bool operator() (const vector<int> &a, const vector<int> &b) const {
//         return a[0] < b[0];
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         intervals.push_back(newInterval);

//         sort(intervals.begin(), intervals.end(), cmp());

//         vector<vector<int>> result;
//         vector<int> currInterval = intervals[0];

//         for(int i=1; i<intervals.size(); ++i) {
//             if(currInterval[0] < intervals[i][0] && currInterval[1] < intervals[i][0]) {
//                 // check for no overlapping
//                 result.push_back(currInterval);
//                 currInterval = intervals[i];
//             } else {
//                 currInterval[0] = min(currInterval[0], intervals[i][0]);
//                 currInterval[1] = max(currInterval[1], intervals[i][1]);
//             }
//         }
//         result.push_back(currInterval);

//         return result;
//     }
// };