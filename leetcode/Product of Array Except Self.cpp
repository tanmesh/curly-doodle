class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // O(N)T, O(N)S
        vector<int> product(nums.size());

        int leftRunningProduct = 1;
        for (int i = 0; i < nums.size(); ++i) {
            product[i] = leftRunningProduct;
            leftRunningProduct *= nums[i];
        }

        int rightRunningProduct = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            product[i] *= rightRunningProduct;
            rightRunningProduct *= nums[i];
        }

        return product;
    }
};