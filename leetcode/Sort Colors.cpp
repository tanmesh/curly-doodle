// Solution 1: using two ptrs
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int leftPtr = 0, rightPtr = nums.size() - 1;
        int i = 0;
        while (i <= rightPtr) {
            if (nums[i] == 0) {
                swap(nums[i], nums[leftPtr]);
                ++leftPtr;
                ++i;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[rightPtr]);
                --rightPtr;
            } else {
                ++i;
            }
        }
    }
};

// // Solution 1: using bubble sort, O(N^2)T, O(1)S
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         for(int i=0; i<nums.size(); ++i) {
//             for(int j=0; j+1<nums.size()-i; ++j) {
//                 if(nums[j] > nums[j + 1]) {
//                     swap(nums[j], nums[j + 1]);
//                 }
//             }
//         }
//     }
// };