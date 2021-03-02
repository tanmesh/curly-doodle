// Solution 2: using single BS
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[low] <= nums[mid]) {
                // this means that the first half sub-array is non-rotated subarray.
                if(nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                // this means that the second half sub-array is non-rotated subarray.
                if(nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

// // Solution 1: finding Pivot and then using BS
// class Solution {
// public:
//     int findPivot(vector<int>& nums) {
//         int low = 0, high = nums.size() - 1;

//         if (nums[low] < nums[high]) {
//             return 0;
//         }

//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (nums[mid] > nums[mid + 1]) {
//                 return mid + 1;
//             }
//             if (nums[mid] < nums[low]) {
//                 high = mid - 1;
//             } else {
//                 low = mid + 1;
//             }
//         }

//         return 0;
//     }

//     int binarySearch(vector<int>& nums, int low, int high, int target) {
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (nums[mid] == target) {
//                 return mid;
//             }
//             if (target < nums[mid]) {
//                 high = mid - 1;
//             } else {
//                 low = mid + 1;
//             }
//         }

//         return -1;
//     }

//     int search(vector<int>& nums, int target) {
//         if (nums.size() == 1) {
//             return nums[0] == target ? 0 : -1;
//         }

//         int pivot = findPivot(nums);

//         if (nums[pivot] == target) {
//             return pivot;
//         }
//         if (pivot == 0) {
//             return binarySearch(nums, 0, nums.size() - 1, target);
//         }

//         if (target < nums[0]) {
//             return binarySearch(nums, pivot, nums.size() - 1, target);
//         }
//         return binarySearch(nums, 0, pivot, target);
//     }
// };