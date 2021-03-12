// solution 2: using priority queue
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> pq;

		for (auto num : nums) {
			if (pq.size() < k) {
				pq.push(num);
			} else if (num >= pq.top()) {
				pq.push(num);
				if (pq.size() > k) {
					pq.pop();
				}
			}
		}

		return pq.top();
	}
};

// // Solution 1: using quickselect
// class Solution {
//     int partition(vector<int> &nums, int low, int high) {
//         int pivot = low;
//         int leftHandSide = low + 1;
//         int rightHandSide = low + 1;
        
//         while(rightHandSide <= high) {
//             if(nums[rightHandSide] < nums[pivot]) {
//                 swap(nums[leftHandSide], nums[rightHandSide]);
//                 ++leftHandSide;
//             }
//             ++rightHandSide;
//         }
//         swap(nums[pivot], nums[leftHandSide - 1]);
//         return leftHandSide - 1;
//     }
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int low = 0, high = nums.size() - 1;
//         k = nums.size() - k;
//         while(true) {
//             int pivot = partition(nums, low, high);
//             if(pivot == k) {
//                 return nums[k];
//             } else if(pivot < k) {
//                 low = pivot + 1;
//             } else {
//                 high = pivot - 1;
//             }
//         }
//         return -1;
//     }
// };