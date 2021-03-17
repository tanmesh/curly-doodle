class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left = 0;
        int cumulativeSum = nums[left];
        int maxSum = cumulativeSum;
        
        for(int right = 1; right < nums.size(); ++right) {
            cumulativeSum += nums[right];
            
            if(nums[right] >= cumulativeSum) {
                left = right;
                cumulativeSum = nums[left];
            }
            
            maxSum = max(maxSum, cumulativeSum);
        }
        
        return maxSum;
    }
};

// class Solution {
//     int crossSum(vector<int> &nums, int left, int right, int mid) {
//         if(left == right) {
//             return nums[left];
//         }
        
//         int leftSubSum = INT_MIN;
//         int currSum = 0;
//         for(int i=mid; i>=left; --i) {
//             currSum += nums[i];
//             leftSubSum = max(leftSubSum, currSum);
//         }
        
//         int rightSubSum = INT_MIN;
//         currSum = 0;
//         for(int i=mid+1; i<=right; ++i) {
//             currSum += nums[i];
//             rightSubSum = max(rightSubSum, currSum);
//         }
        
//         return leftSubSum + rightSubSum;
//     }
    
//     int helper(vector<int> &nums, int left, int right) {
//         if(left == right) {
//             return nums[left];
//         }
        
//         int mid = left + (right - left)/2;
//         int leftSum = helper(nums, left, mid);
//         int rightSum = helper(nums, mid+1, right);
//         int crosssum = crossSum(nums, left, right, mid);
        
//         return max({leftSum, crosssum, rightSum});
//     }
// public:
//     int maxSubArray(vector<int>& nums) {
//         return helper(nums, 0, nums.size()-1);
//     }
// };