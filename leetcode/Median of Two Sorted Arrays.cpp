class Solution {
    int median1;
    int median2;
    int median1Element;
    int median2Element;
    
    void updateMedianElements(int k, int nums) {
        if(k == median1) {
            median1Element = nums;
        }
        if(k == median2) {
            median2Element = nums;
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        
        median1 = n/2;
        median2 = n % 2 == 0 ? median1 - 1 : median1;
        
        int k = 0;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] <= nums2[j]) {
                updateMedianElements(k, nums1[i]);
                ++i;
                ++k;
            } else {
                updateMedianElements(k, nums2[j]);
                ++j;
                ++k;
            } 
        }
        while(i < nums1.size()) {
            updateMedianElements(k, nums1[i]);
            ++i; 
            ++k;
        }
        while(j < nums2.size()) {
            updateMedianElements(k, nums2[j]);
            ++j;
            ++k;
        }
        
        return (median1Element + median2Element)/2.0;
    }
};
// // Solution 1: Using mergesort trick; O(N + M)T, O(N + M)S
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> nums;
        
//         int i = 0, j = 0;
//         while(i < nums1.size() && j < nums2.size()) {
//             if(nums1[i] <= nums2[j]) {
//                 nums.push_back(nums1[i]);
//                 ++i;
//             } else {
//                 nums.push_back(nums2[j]);
//                 ++j;
//             }
//         }
//         while(i < nums1.size()) {
//             nums.push_back(nums1[i]);
//             ++i; 
//         }
//         while(j < nums2.size()) {
//             nums.push_back(nums2[j]);
//             ++j; 
//         }
        
//         double ans = 0.0;
//         int n = nums.size();
//         if(n % 2 == 0) {
//             ans = (nums[n/2] + nums[n/2 - 1])/2.0;
//         } else {
//             ans = nums[n/2];
//         }
        
//         return ans;
//     }
// };