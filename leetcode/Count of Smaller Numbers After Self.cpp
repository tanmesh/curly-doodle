/*
    First solution cunsumed double memory and time ompared to the second solution, due to Vector Amortization.
    Though both have same implementation.
    
    First solution has 1036 ms ms run time and 462.1 MB memory
    
    Second solution has 504 ms run time and 216.2 MB memory
*/

class Solution {
    void merge(vector<pair<int, int>> &nums, int low, int mid, int high, vector<int> &result) {
        int leftHalfPtr = low;
        int rightHalfPtr = mid + 1;
        
        vector<pair<int, int>> tmpSort;
        while(leftHalfPtr <= mid && rightHalfPtr <= high) {
            if(nums[leftHalfPtr].first <= nums[rightHalfPtr].first) {
                tmpSort.push_back(nums[rightHalfPtr]);
                ++rightHalfPtr;
            } else {
                result[nums[leftHalfPtr].second] += high - rightHalfPtr + 1;
                tmpSort.push_back(nums[leftHalfPtr]);
                ++leftHalfPtr;
            }
        }
        while(leftHalfPtr <= mid) {
            tmpSort.push_back(nums[leftHalfPtr]);
            ++leftHalfPtr;
        }
        while(rightHalfPtr <= high) {
            tmpSort.push_back(nums[rightHalfPtr]);
            ++rightHalfPtr;
        }
        
        for(int i=low; i<=high; ++i) {
            nums[i] = tmpSort[i - low];
        }
    }
    
    void mergeSort(vector<pair<int, int>> &nums, int low, int high, vector<int> &result) {
        if(low < high) {
            int mid = low + (high - low)/2;
            mergeSort(nums, low, mid, result);
            mergeSort(nums, mid+1, high, result);
            merge(nums, low, mid, high, result);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        
        vector<pair<int, int>> arr;
        for(int i=0; i<nums.size(); ++i) {
            arr.push_back({nums[i], i});
        }
        
        mergeSort(arr, 0, arr.size()-1, result);
        
        return result;
    }
};

// class Solution {
//     void merge(vector<pair<int, int>> &nums, int low, int mid, int high, vector<int> &result) {
//         int leftHalfPtr = low;
//         int rightHalfPtr = mid + 1;
//         int k = 0;
        
//         vector<pair<int, int>> tmpSort(high - low + 1);
        
//         while(leftHalfPtr <= mid && rightHalfPtr <= high) {
//             if(nums[leftHalfPtr].first <= nums[rightHalfPtr].first) {
//                 tmpSort[k++] = nums[rightHalfPtr++];
//             } else {
//                 result[nums[leftHalfPtr].second] += high - rightHalfPtr + 1;
//                 tmpSort[k++] = nums[leftHalfPtr++];
//             }
//         }
        
//         while(leftHalfPtr <= mid) {
//             tmpSort[k++] = nums[leftHalfPtr++];
//         }
//         while(rightHalfPtr <= high) {
//             tmpSort[k++] = nums[rightHalfPtr++];
//         }
        
//         for(int i=low; i<=high; ++i) {
//             nums[i] = tmpSort[i - low];
//         }
//     }
    
//     void mergeSort(vector<pair<int, int>> &nums, int low, int high, vector<int> &result) {
//         if(low < high) {
//             int mid = low + (high - low)/2;
//             mergeSort(nums, low, mid, result);
//             mergeSort(nums, mid+1, high, result);
//             merge(nums, low, mid, high, result);
//         }
//     }
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         vector<int> result(nums.size(), 0);
        
//         vector<pair<int, int>> arr;
//         for(int i=0; i<nums.size(); ++i) {
//             arr.push_back({nums[i], i});
//         }
        
//         mergeSort(arr, 0, arr.size()-1, result);
        
//         return result;
//     }
// };